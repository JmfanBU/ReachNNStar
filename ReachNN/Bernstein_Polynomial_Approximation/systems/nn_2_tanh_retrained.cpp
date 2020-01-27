#include "../flowstar/Continuous.h"
#include "bernstein_poly_approx.h"
#include<fstream>
#include<ctime>

using namespace std;
using namespace flowstar;


int main()
{
	// Declaration of the state variables.
	unsigned int numVars = 3;

	int x0_id = stateVars.declareVar("x0");
	int x1_id = stateVars.declareVar("x1");
	int u_id = stateVars.declareVar("u");

	int domainDim = numVars + 1;


	// Define the continuous dynamics.
	Expression_AST<Real> deriv_x0("x1 - x0^3");  // theta_r = 0
	Expression_AST<Real> deriv_x1("u");
	Expression_AST<Real> deriv_u("0");

	vector<Expression_AST<Real> > ode_rhs(numVars);
	ode_rhs[x0_id] = deriv_x0;
	ode_rhs[x1_id] = deriv_x1;
	ode_rhs[u_id] = deriv_u;

	Deterministic_Continuous_Dynamics dynamics(ode_rhs);

	// Specify the parameters for reachability computation.

	Computational_Setting setting;

	unsigned int order = 12;

	// stepsize and order for reachability analysis
	setting.setFixedStepsize(0.01, order);

	// time horizon for a single control step
	setting.setTime(0.2);

	// cutoff threshold
	setting.setCutoffThreshold(1e-10);

	// queue size for the symbolic remainder
	setting.setQueueSize(1000);

	// print out the steps
	setting.printOn();

	// remainder estimation
	Interval I(-0.01, 0.01);
	vector<Interval> remainder_estimation(numVars, I);
	setting.setRemainderEstimation(remainder_estimation);

	setting.printOff();

	setting.prepare();

	/*
	 * Initial set can be a box which is represented by a vector of intervals.
	 * The i-th component denotes the initial set of the i-th state variable.
	 */
	Interval init_x0(0.7,0.9), init_x1(0.7,0.9), init_u(0);
	std::vector<Interval> X0;
	X0.push_back(init_x0);
	X0.push_back(init_x1);
	X0.push_back(init_u);




	// translate the initial set to a flowpipe
	Flowpipe initial_set(X0);

	// no unsafe set
	vector<Constraint> unsafeSet;

	// result of the reachability computation
	Result_of_Reachability result;

	// define the neural network controller
	char const *module_name = "controller_approximation_lib";
	char const *function_name1 = "poly_approx_controller";
	char const *function_name2 = "poly_approx_error";
	char const *function_name3 = "network_lips";
	char const *degree_bound = "[5, 5]";
	char const *activation = "tanh";
	char const *output_index = "0";
	char const *neural_network = "nn_2_tanh_retrained";


	double err_max = 0;
	time_t start_timer;
	time_t end_timer;
	double seconds;
	time(&start_timer);

	// perform 7 control steps
	for(int iter=0; iter<7; ++iter)
	{
		vector<Interval> box;
		initial_set.intEval(box, order, setting.tm_setting.cutoff_threshold);

		string strBox = "[" + box[0].toString() + "," + box[1].toString() + "]";

		string strExpU = bernsteinPolyApproximation(module_name, function_name1, degree_bound, strBox.c_str(), activation, output_index, neural_network);

		double err = stod(bernsteinPolyApproximation(module_name, function_name2, degree_bound, strBox.c_str(), activation, output_index, neural_network));

		if (err >= err_max)
		{
			err_max = err;
		}

		Expression_AST<Real> exp_u(strExpU);

		TaylorModel<Real> tm_u;
		exp_u.evaluate(tm_u, initial_set.tmvPre.tms, order, initial_set.domain, setting.tm_setting.cutoff_threshold, setting.g_setting);

		tm_u.remainder.bloat(err);

		initial_set.tmvPre.tms[u_id] = tm_u;

		dynamics.reach(result, setting, initial_set, unsafeSet);

		if(result.status == COMPLETED_SAFE || result.status == COMPLETED_UNSAFE || result.status == COMPLETED_UNKNOWN)
		{
			initial_set = result.fp_end_of_time;
		}
		else
		{
			printf("Terminated due to too large overestimation.\n");
		}
	}

	vector<Interval> end_box;
	string reach_result;
	reach_result = "Verification result: Unknown(7)";
	result.fp_end_of_time.intEval(end_box, order, setting.tm_setting.cutoff_threshold);

	if(end_box[0].inf() >= -0.3 && end_box[0].sup() <= 0.1 && end_box[1].inf() >= -0.35 && end_box[1].sup() <= 0.5){
		reach_result = "Verification result: Yes(7)";
	}

	if(end_box[0].inf() >= 0.1 || end_box[0].sup() <= -0.3 || end_box[1].inf() >= 0.5 || end_box[1].sup() <= -0.35){
		reach_result = "Verification result: No(7)";
	}

	time(&end_timer);
	seconds = difftime(start_timer, end_timer);

	// plot the flowpipes in the x-y plane
	result.transformToTaylorModels(setting);

	Plot_Setting plot_setting;
	plot_setting.setOutputDims(x0_id, x1_id);

	int mkres = mkdir("./outputs", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if(mkres < 0 && errno != EEXIST)
	{
		printf("Can not create the directory for images.\n");
		exit(1);
	}

	std::string err_max_str = "Max Error: " + std::to_string(err_max);
	std::string running_time = "Running Time: " + std::to_string(-seconds) + " seconds";

	ofstream result_output("./outputs/nn_2_tanh_retrained.txt");
	if (result_output.is_open())
	{
		result_output << reach_result << endl;
		result_output << err_max_str << endl;
		result_output << running_time << endl;
	}
	// you need to create a subdir named outputs
	// the file name is example.m and it is put in the subdir outputs
	plot_setting.plot_2D_interval_GNUPLOT("nn_2_tanh_retrained", result);

	return 0;
}

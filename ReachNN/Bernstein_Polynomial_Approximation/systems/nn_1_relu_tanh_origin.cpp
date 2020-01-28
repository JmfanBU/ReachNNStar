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
	Expression_AST<Real> deriv_x0("x1");  // theta_r = 0
	Expression_AST<Real> deriv_x1("u*x1^2-x0");
	Expression_AST<Real> deriv_u("0");

	vector<Expression_AST<Real> > ode_rhs(numVars);
	ode_rhs[x0_id] = deriv_x0;
	ode_rhs[x1_id] = deriv_x1;
	ode_rhs[u_id] = deriv_u;

	Deterministic_Continuous_Dynamics dynamics(ode_rhs);




	// Specify the parameters for reachability computation.

	Computational_Setting setting;

	unsigned int order = 8;

	// stepsize and order for reachability analysis
	setting.setFixedStepsize(0.005, order);

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
	Interval init_x0(0.8, 0.9), init_x1(0.5, 0.6), init_u(0);
	std::vector<Interval> X0;
	X0.push_back(init_x0);
	X0.push_back(init_x1);
	X0.push_back(init_u);




	// translate the initial set to a flowpipe
	Flowpipe initial_set(X0);

	vector<Constraint> unsafeSet;
	Constraint constraint_unsafe_1("x0 - 0.8");
	Constraint constraint_unsafe_2("-x0 + 0.3");
	Constraint constraint_unsafe_3("x1 - 0.4");
	Constraint constraint_unsafe_4("-x1 - 0.1");
	unsafeSet.push_back(constraint_unsafe_1);
	unsafeSet.push_back(constraint_unsafe_2);
	unsafeSet.push_back(constraint_unsafe_3);
	unsafeSet.push_back(constraint_unsafe_4);

	vector<Constraint> targetSet;
	Constraint constraint_target_1("x0 - 0.2");
	Constraint constraint_target_2("-x0");
	Constraint constraint_target_3("-x1 + 0.3");
	Constraint constraint_target_4("x1 - 0.05");
	targetSet.push_back(constraint_target_1);
	targetSet.push_back(constraint_target_2);
	targetSet.push_back(constraint_target_3);
	targetSet.push_back(constraint_target_4);

	// result of the reachability computation
	Result_of_Reachability result;

	// define the neural network controller
	char const *module_name = "controller_approximation_lib";
	char const *function_name1 = "poly_approx_controller";
	char const *function_name2 = "poly_approx_error";
	char const *function_name3 = "network_lips";
	char const *degree_bound = "[3, 3]";
	char const *activation = "ReLU_tanh";
	char const *output_index = "0";
	char const *neural_network = "nn_1_relu_tanh_origin";

	double err_max = 0;
	time_t start_timer;
	time_t end_timer;
	double seconds;
	string reach_avoid_result;
	reach_avoid_result = "Unknown";
	time(&start_timer);

	// perform 35 control steps
	for (int iter = 0; iter < 35; ++iter)
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

		dynamics.reach_while_avoid(result, setting, initial_set, unsafeSet, targetSet);

		if (result.status == COMPLETED_UNSAFE || result.status == SAFE_REACHABLE || result.status == UNKNOWN_REACHABLE){
			if (result.status == COMPLETED_UNSAFE){
				reach_avoid_result = "Hitting the obstacles!";
				break;
			}
			if (result.status == UNKNOWN_REACHABLE){
				reach_avoid_result = "Reach without safety guarantees.";
				break;
			}
		}

		if (result.status == COMPLETED_SAFE || result.status == COMPLETED_UNSAFE || result.status == COMPLETED_UNKNOWN || result.status == SAFE_REACHABLE)
		{
			initial_set = result.fp_end_of_time;
		}
		else
		{
			printf("Terminated due to too large overestimation.\n");
			break;
		}
	}

	vector<Interval> end_box;
	result.fp_end_of_time.intEval(end_box, order, setting.tm_setting.cutoff_threshold);

	if(end_box[0].inf() >= 0.0 && end_box[0].sup() <= 0.2 && end_box[1].inf() >= 0.05 && end_box[1].sup() <= 0.3){
		reach_avoid_result = "Safe and reachable!";
	}

	if(end_box[0].inf() > 0.2 || end_box[0].sup() < 0.0 || end_box[1].inf() > 0.3 || end_box[1].sup() < 0.05){
		reach_avoid_result = "Verification result: No(35)";
	}

	time(&end_timer);
	seconds = difftime(start_timer, end_timer);

	// plot the flowpipes in the x-y plane
	result.transformToTaylorModels(setting);

	Plot_Setting plot_setting;
	plot_setting.setOutputDims(x0_id, x1_id);

	int mkres = mkdir("./outputs", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if (mkres < 0 && errno != EEXIST)
	{
		printf("Can not create the directory for images.\n");
		exit(1);
	}

	std::string err_max_str = "Max Error: " + std::to_string(err_max);
	std::string running_time = "Running Time: " + std::to_string(-seconds) + " seconds";

	ofstream result_output("./outputs/nn_1_relu_tanh_origin.txt");
	if (result_output.is_open())
	{
		result_output << reach_avoid_result << endl;
		result_output << err_max_str << endl;
		result_output << running_time << endl;
	}
	// you need to create a subdir named outputs
	// the file name is example.m and it is put in the subdir outputs
	plot_setting.plot_2D_interval_GNUPLOT("nn_1_relu_tanh_origin", result);

	return 0;
}

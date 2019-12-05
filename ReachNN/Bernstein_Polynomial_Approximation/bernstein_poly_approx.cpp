#include "./bernstein_poly_approx.h"

string bernsteinPolyApproximation(char const *module_name, char const *function_name, char const *degree_bound, char const *box, char const *activation, char const *output_index, char const *neural_network)
{
	PyObject *pName, *pModule, *pFunc;
	PyObject *pArgs, *pValue;
	int i;

	Py_Initialize();
	PyRun_SimpleString("import sys, os");
	PyRun_SimpleString("sys.path.append(\".\")");
	//PyRun_SimpleString("print(sys.path)");

	pName = PyUnicode_DecodeFSDefault(module_name);
	/* Error checking of pName left out */

	pModule = PyImport_Import(pName);
	Py_DECREF(pName);

	if (pModule != NULL) {
		pFunc = PyObject_GetAttrString(pModule, function_name);
		/* pFunc is a new reference */

		if (pFunc && PyCallable_Check(pFunc)) {
			if (strcmp("poly_approx_controller", function_name) == 0) {
				//cout << "try: dubins_poly_controller, but invoke: " << function_name << "  " << strcmp("dubins_poly_controller", function_name) << endl;
				
				pArgs = PyTuple_New(5);

				PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(degree_bound));
				PyTuple_SetItem(pArgs, 1, PyUnicode_FromString(box));
				PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(output_index));
				PyTuple_SetItem(pArgs, 3, PyUnicode_FromString(activation));
				PyTuple_SetItem(pArgs, 4, PyUnicode_FromString(neural_network));

				pValue = PyObject_CallObject(pFunc, pArgs);
				Py_DECREF(pArgs);
				if (pValue != NULL) {
					//cout << "Result of call: " << PyUnicode_AsUTF8(pValue) << endl;
					return PyUnicode_AsUTF8(pValue);
					Py_DECREF(pValue);
				}
				else {
					Py_DECREF(pFunc);
					Py_DECREF(pModule);
					PyErr_Print();
					fprintf(stderr, "Call failed\n");
					return "11";
				}
			}
			else if (strcmp("poly_approx_error", function_name) == 0) {
				//cout << "try: poly_approx_error, but invoke: " << function_name << "  " << strcmp("dubins_poly_controller", function_name) << endl;

				pArgs = PyTuple_New(5);

				PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(degree_bound));
				PyTuple_SetItem(pArgs, 1, PyUnicode_FromString(box));
				PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(output_index));
				PyTuple_SetItem(pArgs, 3, PyUnicode_FromString(activation));
				PyTuple_SetItem(pArgs, 4, PyUnicode_FromString(neural_network));

				pValue = PyObject_CallObject(pFunc, pArgs);
				Py_DECREF(pArgs);
				if (pValue != NULL) {
					//cout << "Result of call: " << PyUnicode_AsUTF8(pValue) << endl;
					string error_bound_str = PyUnicode_AsUTF8(pValue);
					//return stod(error_bound_str);
					return error_bound_str;
					Py_DECREF(pValue);
				}
				else {
					Py_DECREF(pFunc);
					Py_DECREF(pModule);
					PyErr_Print();
					fprintf(stderr, "Call poly_approx_error failed\n");
					return "12";
				}
			}
			else if (strcmp("network_lips", function_name) == 0) {
				pArgs = PyTuple_New(2);

				PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(box));
				PyTuple_SetItem(pArgs, 1, PyUnicode_FromString(activation));


				pValue = PyObject_CallObject(pFunc, pArgs);
				Py_DECREF(pArgs);
				if (pValue != NULL) {
					//cout << "Result of call: " << PyUnicode_AsUTF8(pValue) << endl;
					string error_bound_str = PyUnicode_AsUTF8(pValue);
					//return stod(error_bound_str);
					return error_bound_str;
					Py_DECREF(pValue);
				}
				else {
					Py_DECREF(pFunc);
					Py_DECREF(pModule);
					PyErr_Print();
					fprintf(stderr, "Call poly_approx_error failed\n");
					return "12";
				}
			}
			else if (strcmp("network_output_range_center", function_name) == 0) {
				//cout << "try: poly_approx_error, but invoke: " << function_name << "  " << strcmp("dubins_poly_controller", function_name) << endl;

				pArgs = PyTuple_New(5);

				PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(degree_bound));
				PyTuple_SetItem(pArgs, 1, PyUnicode_FromString(box));
				PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(output_index));
				PyTuple_SetItem(pArgs, 3, PyUnicode_FromString(activation));
				PyTuple_SetItem(pArgs, 4, PyUnicode_FromString(neural_network));

				pValue = PyObject_CallObject(pFunc, pArgs);
				Py_DECREF(pArgs);
				if (pValue != NULL) {
					//cout << "Result of call: " << PyUnicode_AsUTF8(pValue) << endl;
					string error_bound_str = PyUnicode_AsUTF8(pValue);
					//return stod(error_bound_str);
					return error_bound_str;
					Py_DECREF(pValue);
				}
				else {
					Py_DECREF(pFunc);
					Py_DECREF(pModule);
					PyErr_Print();
					fprintf(stderr, "Call network_output_range_center failed\n");
					return "12";
				}
			}
			else if (strcmp("network_output_range_radius", function_name) == 0) {
				//cout << "try: poly_approx_error, but invoke: " << function_name << "  " << strcmp("dubins_poly_controller", function_name) << endl;

				pArgs = PyTuple_New(5);

				PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(degree_bound));
				PyTuple_SetItem(pArgs, 1, PyUnicode_FromString(box));
				PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(output_index));
				PyTuple_SetItem(pArgs, 3, PyUnicode_FromString(activation));
				PyTuple_SetItem(pArgs, 4, PyUnicode_FromString(neural_network));

				pValue = PyObject_CallObject(pFunc, pArgs);
				Py_DECREF(pArgs);
				if (pValue != NULL) {
					//cout << "Result of call: " << PyUnicode_AsUTF8(pValue) << endl;
					string error_bound_str = PyUnicode_AsUTF8(pValue);
					//return stod(error_bound_str);
					return error_bound_str;
					Py_DECREF(pValue);
				}
				else {
					Py_DECREF(pFunc);
					Py_DECREF(pModule);
					PyErr_Print();
					fprintf(stderr, "Call network_output_range_radius failed\n");
					return "12";
				}
			}
		}
		else {
			if (PyErr_Occurred())
				PyErr_Print();
			cout << "Cannot find function: " << function_name << endl;
		}
		Py_XDECREF(pFunc);
		Py_DECREF(pModule);
	}
	else {
		PyErr_Print();
		fprintf(stderr, "Failed to load \"%s\"\n", module_name);
		return "1";
	}
	if (Py_FinalizeEx() < 0) {
		return "120";
	}
	return "0";
}



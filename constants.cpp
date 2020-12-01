#include "constants.h"

void log(string s) 
{
     clog << s << endl;
}

string exist_errors[100];

void load_errors()
{
	exist_errors[(size_t)success] = "no error";
	exist_errors[(size_t)no_operation] = "no such operation";
	exist_errors[(size_t)zero_data_points_in_interval] = "no data points in interval";
	exist_errors[(size_t)problem_with_file] = "can't read tje file";
	exist_errors[(size_t)bad_timestamp] = "problem with timestamp";
	exist_errors[(size_t)read_data_point_error] = "problem while reading datapoint";
	//exist_errors[(size_t)no_operation] = "no such operation";
	//exist_errors[(size_t)no_operation] = "no such operation";

}

	

void log_error(type_error error_code, string location)
{
	cerr << location << " ";
	cerr << "ERROR " << (size_t)error_code << " : ";
	if(sizeof(exist_errors) < (size_t)error_code)
		cerr << "strange error, no description for this error" << endl;		
	else
		cerr << exist_errors[(size_t)error_code] << endl;
}




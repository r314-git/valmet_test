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
	exist_errors[(size_t)problem_with_file] = "can't read the file";
	exist_errors[(size_t)bad_timestamp] = "problem with timestamp";
	exist_errors[(size_t)read_data_point_error] = "problem while reading datapoint";
	exist_errors[(size_t)problem_n_data_point] = "problem reading number of data_points";
	exist_errors[(size_t)file_name_error] = "cant read file name";
	exist_errors[(size_t)bad_lr_params] = "left or right border is incorrect";
	exist_errors[(size_t)swap_lr_params] = "left and right borders are swapped";
	exist_errors[(size_t)read_data_point_error_quality] = "problem while reading datapoint: incorrect quality";
	exist_errors[(size_t)read_timestamp_error] = "problem while reading timestamp";
	exist_errors[(size_t)ns_timestamp_error] = "problem while reading timestamp: nanosecond more or equal to 1e9";
	exist_errors[(size_t)value_timestamp_error] = "problem while reading timestamp: too big in sec*1e9 + nanosecond";
	exist_errors[(size_t)end_operation_list] = "problem while reading operation";

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




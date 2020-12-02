#pragma once

#include<bits/stdc++.h>
using namespace std;


#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION string(__func__) + " : " + S2(__FILE__) + " : " + S2(__LINE__) + " : " 
#define MAXTIME 18446744073000000000ull
#define ten_9 1000000000ull


typedef enum {
	success,
	no_operation,
	zero_data_points_in_interval,
	problem_with_file,
	bad_timestamp,
	read_data_point_error,
	problem_n_data_point,
	file_name_error,
	bad_lr_params,
	swap_lr_params,
	read_data_point_error_quality,
	read_timestamp_error,
	ns_timestamp_error,
	value_timestamp_error,
	end_operation_list

} type_error;




void log(string s);
void log_error(type_error error_code, string s);
void load_errors();




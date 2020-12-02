#include "file_reader.h"


type_error file_reader::read_data_points_from_file(string file_name, vector<data_point> &all)
{
	type_error errnom = success;
	ifstream fin;
	fin.open(file_name.c_str());
	if(!fin.is_open()){
		errnom = problem_with_file;
		log_error(errnom, LOCATION);
		return errnom;
	}
	int n;
	fin >> n;
	if(fin.fail())
	{
		fin.close();
		errnom = problem_n_data_point;
		log_error(errnom, LOCATION);
		return errnom;
	}
	for(int i = 0 ; i < n; i ++)
	{
		data_point tmp;
		fin >> tmp;
		if(fin.fail()){
			fin.close();
			errnom = read_data_point_error;
			log_error(errnom, LOCATION);
			return errnom;
		}
		if(tmp.errnom != success)
		{
			fin.close();
			log_error(tmp.errnom, LOCATION);
			return tmp.errnom;
		}
		all.push_back(tmp);
	}
	fin.close();
	return success;
}

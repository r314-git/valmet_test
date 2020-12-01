#include "file_reader.h"


vector<data_point> file_reader::read_data_points_from_file(string file_name, type_error errnom)
	{
		log(LOCATION + string("in filereader in read_data_points_from_file"));
		//cerr << "in filereader in read_data_points_from_file" << endl;
		ifstream fin;
		vector<data_point> all;
		cerr << "trying to open file \"" << file_name << "\"" << endl;
		fin.open(file_name.c_str());
		if(!fin.is_open()){

			cerr << "No such file";
			errnom = problem_with_file;
			return all;
		}
		int n;
		fin >> n;
		for(int i = 0 ; i < n; i ++)
		{
			data_point tmp;
			fin >> tmp;
			all.push_back(tmp);
		}
		cerr << "file was read properly";
		return all;
 	}

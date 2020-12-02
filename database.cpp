#include "database.h"

type_error database::add(string f_name)
{
	file_reader f;
	vector<data_point> all;
	type_error errnom = success;
	errnom = f.read_data_points_from_file(f_name, all);
	if(errnom != success){
		log_error(errnom, LOCATION);
		return errnom;
	}
	for(auto x : all)
		fenwick_tree_data_points.add(x);
		
	return success;
}
type_error database::query(timestamp l,  timestamp r, data_point & result)
{
	return fenwick_tree_data_points.get_sum(l, r, result);
}

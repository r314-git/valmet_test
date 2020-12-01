#include "database.h"

void database::add(string f_name, type_error &errnom)
{
	cerr << "in database in function add" << endl;
	file_reader f;
	vector<data_point> all = f.read_data_points_from_file(f_name, errnom);
	for(auto x : all)
	{
		fenwick_tree_data_points.add(x);
	}
}
void database::query(timestamp l,  timestamp r, data_point & result, type_error &errnom)
{
	pair<long double, int> res = fenwick_tree_data_points.get_sum(l, r, errnom);
	result = data_point(l, res.first, res.second); 
}

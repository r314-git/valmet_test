#pragma once

#include<bits/stdc++.h>
#include "constants.h"
#include "timestamp.h"
#include "data_point.h"
#include "fenwick_tree.h"
#include "file_reader.h"


using namespace std;


class database
{
	public :
		fenwick_tree fenwick_tree_data_points;
		void add(string f_name, type_error &errnom);
		void query(timestamp l,  timestamp r, data_point & result, type_error &errnom);

};
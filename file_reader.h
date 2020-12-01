#pragma once

#include<bits/stdc++.h>
#include "data_point.h"
#include "constants.h"

using namespace std;

class file_reader
{
public:
	//check(string f_name, type_error errnom);
				
	vector<data_point> read_data_points_from_file(string file_name, type_error errnom);

};
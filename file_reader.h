#pragma once

#include<bits/stdc++.h>
#include "data_point.h"
#include "constants.h"

using namespace std;

class file_reader
{
public:
	type_error read_data_points_from_file(string file_name, vector<data_point> &all);

};
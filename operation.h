#pragma once
#include<bits/stdc++.h>
#include "constants.h"
#include "timestamp.h"
#include "data_point.h"
#include "database.h"




using namespace std;

class operation
{
	public:
		static map<string, int> id_operation;
		static int num_of_params[];
		int type_id;
		string f_name; // only for 1 type
		timestamp l, r; // only for 2 type
		operation()
		{
			type_id = 0;
			f_name = "";
		}
		void get_current_operation (type_error &errnom);
		void get_type_of_operation(type_error &errnom);
		void get_params_operation(type_error &errnom);
		void execute_operation(database & db, type_error &errnom, data_point &result);
};
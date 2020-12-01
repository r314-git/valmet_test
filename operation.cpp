#include "operation.h"


void operation::get_current_operation (type_error &errnom)
{		
	if(errnom == success)
		get_type_of_operation(errnom);
	if(errnom == success)	
		get_params_operation(errnom);
}
void operation::get_type_of_operation(type_error &errnom)
{
	if(errnom != success)
		return;
	string name_type;
	cin >> name_type;
	if(id_operation.count(name_type) != 1)
	{
		errnom = no_operation;
		return;
	}
	type_id = id_operation[name_type];
}
void operation::get_params_operation(type_error &errnom)
{
	if(errnom != success)
		return;
	switch(type_id)
	{
		case 1:
		{
			cin >> f_name;
			cerr << "file name for add was read" << endl;
			break;
		}	
		case 2:
		{
			cin >> l >> r;
			break;
		}
		default:
			break;
	}
}
void operation::execute_operation(database & db, type_error &errnom, data_point &result)
{
	if(errnom != success)
		return;
	switch(type_id)
	{
		case 1: 	
			db.add(f_name, errnom);
			break;
		case 2:
			db.query(l, r, result, errnom);
			break;
		
	}
}
int operation :: num_of_params[] = {0, 1, 2};
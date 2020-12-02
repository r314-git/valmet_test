#include "operation.h"


type_error operation::get_current_operation()
{		
	type_error errnom = get_type_of_operation();
	if(errnom != success){
		log_error(errnom, LOCATION);
		return errnom;
	}
	errnom = get_params_operation();
	if(errnom != success){
		log_error(errnom, LOCATION);
		return errnom;
	}
	return success;
	
}
type_error  operation::get_type_of_operation()
{
	type_error errnom = success;
	string name_type;
	cout << "enter the type of operation from following list:" << endl;
	for(auto op : id_operation)
	{
		cout << op.first << " ";
	}
	cout << endl;

	cin >> name_type;
	if(cin.fail() || cin.bad())
	{
		errnom = end_operation_list;
		log_error(errnom, LOCATION + " op = " + name_type);
		return errnom;
		
	}
	if(id_operation.count(name_type) != 1)
	{
		errnom = no_operation;
		log_error(errnom, LOCATION + " op = " + name_type);
		return errnom;
	}
	type_id = id_operation[name_type];
	return success;
}
type_error operation::get_params_operation()
{
	type_error errnom = success;
	switch(type_id)
	{
		case 1:
		{
			cin >> f_name;
			if(cin.fail())
			{
				errnom = file_name_error;
				log_error(errnom, LOCATION);
				return errnom;
			}
			break;
		}	
		case 2:
		{
			cin >> l;
			if(cin.fail() || cin.bad() || l.errnom != success)
			{
				errnom = bad_lr_params;
				log_error(errnom, LOCATION);
				return errnom;
			}
			cin >> r;
			if(cin.fail() || cin.bad() || r.errnom != success)
			{
				errnom = bad_lr_params;
				log_error(errnom, LOCATION);
				return errnom;
			}
			if(r < l)
			{
				errnom = swap_lr_params;
				log_error(errnom, LOCATION);
				return errnom;
			}
			break;
		}
		default:
			break;
	}
	return success;
}
type_error operation::execute_operation(database & db, data_point &result)
{
	switch(type_id)
	{
		case 0:
			return success;
		case 1: 	
			return db.add(f_name);
		case 2:
			return db.query(l, r, result);
	}
	type_error errnom = no_operation;
	log_error(errnom, LOCATION);
	return errnom;
	
}
int operation :: num_of_params[] = {0, 1, 2};
map<string, int> operation :: id_operation  = {{"exit", 0}, {"add", 1}, {"get_mean", 2}};

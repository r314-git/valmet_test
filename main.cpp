#include "all.h"


database db;


void main_loop()
{	
	operation tmp_operation;
	type_error errnom;
	data_point result;

	while(true)
	{
		errnom = tmp_operation.get_current_operation();
		if(errnom != success){
			log_error(errnom, LOCATION);
			if(errnom == end_operation_list)
				break;
		}
		else	
		{
			errnom = tmp_operation.execute_operation(db, result);
			if(errnom != success)
				log_error(errnom, LOCATION);
			else{
				if(tmp_operation.type_id == 0)
					break;
				if(tmp_operation.type_id == 1)
					cout << "datapoints were successfully added" << endl;
				if(tmp_operation.type_id == 2)
					cout << "result : " << result << endl;
			}
		} 
		
	}	
}

int main()
{
	load_errors();
	main_loop();
	return 0;
}


/*
1606758728 * 1e9 + ns
50
3.2 * 1.e9 * 1e8
3.2 * 1.18
9 223 372 036 854 775 
18446744073000000000
		   999999999 
		   709551615
18446744072
18 * 1e18
the last day of this programm
 Sunday, 21 July 2554 г., 23:34:32
 /// only for the nearest 400 years

 */
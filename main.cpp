#include "all.h"

extern string exist_errors[];

database db;



map<string, int> operation :: id_operation  = {{"add", 1}, {"get mean", 2}};


void main_loop()
{	
	operation tmp_operation;
	type_error errnom;
	data_point result;
	while(true)
	{
		type_error errnom = success;
		tmp_operation.get_current_operation(errnom);
		if(errnom != success)
			cout << exist_errors[errnom] << endl;
		else
			if(errnom == success)
				tmp_operation.execute_operation(db, errnom, result);
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
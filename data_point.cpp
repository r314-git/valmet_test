#include "data_point.h"

istream &operator >> (istream & in, data_point & tmp)
{
	in >> tmp.ts >> tmp.value >> tmp.quality;
	if(tmp.ts.errnom != success)
		tmp.errnom = tmp.ts.errnom;
	if(in.fail() || in.bad()){
		tmp.errnom = read_data_point_error;
		log_error(tmp.errnom, LOCATION);
	}

	return in;
}

#include "data_point.h"

istream &operator >> (istream & in, data_point & tmp)
{
	in >> tmp.ts >> tmp.value >> tmp.quality;
	if(tmp.ts.errnom != success){
		tmp.errnom = tmp.ts.errnom;
		log_error(tmp.errnom, LOCATION);
		return in;
	}
	if(in.fail() || in.bad()){
		tmp.errnom = read_data_point_error;
		log_error(tmp.errnom, LOCATION);
		return in;
	}
	if(tmp.quality > 2 || tmp.quality < 0){
		tmp.errnom = read_data_point_error_quality;
		log_error(tmp.errnom, LOCATION);
		return in;
	}
	

	return in;
}

ostream &operator << (ostream & out, data_point & tmp)
{
	out << tmp.ts << ", value: " << tmp.value << ", quality: " << tmp.quality;
	return out;
}

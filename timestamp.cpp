#include "timestamp.h"

istream &operator >> (istream & in, timestamp & tmp)
{
	in >> tmp.s >> tmp.ns;

	if(in.fail() || in.bad()){
		tmp.errnom = read_timestamp_error;
		log_error(tmp.errnom, LOCATION);
		return in;
	}

	if(tmp.ns >= ten_9 ){
		tmp.errnom = ns_timestamp_error;
		log_error(tmp.errnom, LOCATION);
		return in;
	}
	
	
	if(tmp.to_nanosec() > MAXTIME ){
		tmp.errnom = value_timestamp_error;
		log_error(tmp.errnom, LOCATION);
		return in;
	}

	return in;
}


ostream &operator << (ostream & out, timestamp & tmp)
{
	out << "{" << tmp.s << ", " << tmp.ns << "}";
	return out;
}

bool operator < (const timestamp & l, const timestamp & r)
{
	return l.to_nanosec() < r.to_nanosec();
}

unsigned long long timestamp::to_nanosec() const
{
	return s * ten_9 + ns;
}
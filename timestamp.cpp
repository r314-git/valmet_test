#include "timestamp.h"

istream &operator >> (istream & in, timestamp & tmp)
{
	in >> tmp.s >> tmp.ns;
	if(in.fail() || tmp.s * ten_9 + tmp.ns > MAXTIME)
		tmp.errnom = bad_timestamp;

	return in;
}


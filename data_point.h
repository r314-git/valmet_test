#pragma once

#include<bits/stdc++.h>
#include "timestamp.h"
#include "constants.h"

using namespace std;


class data_point
{
	public:
		type_error errnom;
		timestamp ts;
		long double value;
		int quality;

		data_point(){}
		data_point(timestamp ts, long double value, int quality) : ts(ts), value(value), quality(quality)
		{
			errnom = success;
		} 

};


istream &operator >> (istream & in, data_point & tmp);
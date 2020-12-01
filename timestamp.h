#pragma once

#include<bits/stdc++.h>
#include "constants.h"

using namespace std;


class timestamp
{	
	public:
		type_error errnom;
		long long s;
		int ns;
		timestamp(){}
		timestamp(const timestamp &x)
		{
			errnom = success;
			s = x.s;
			ns = x.ns;
		}
};

istream &operator >> (istream & in, timestamp & tmp);


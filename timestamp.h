#pragma once

#include<bits/stdc++.h>
#include "constants.h"

using namespace std;


class timestamp
{	
	public:
		type_error errnom;
		unsigned long long s;
		unsigned long long ns;
		timestamp(){
			errnom = success;
		}
		timestamp(const timestamp &x)
		{
			errnom = success;
			s = x.s;
			ns = x.ns;
		}
		unsigned long long to_nanosec() const;
};

istream &operator >> (istream & in, timestamp & tmp);
ostream &operator << (ostream & out, timestamp & tmp);
bool operator < (const timestamp & l, const timestamp & r);


#pragma once

#include<bits/stdc++.h>
using namespace std;

class query_ans{
public:
	unsigned long long n;
	long double sum_value;
	unsigned long long quality[3];
	query_ans()
	{
		n = 0;
		sum_value = 0;
		for(int i = 0; i < 3; i++)
			quality[i] = 0;
	}
};

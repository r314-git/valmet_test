#pragma once
#include<bits/stdc++.h>
#include "constants.h"
#include "timestamp.h"
#include "data_point.h"
#include "query_ans.h"
#include "fenwick_tree.h"



using namespace std;


class fenwick_tree
{
	map<unsigned long long, long double> fenwick_tree_value;
	map<unsigned long long, unsigned long long> fenwick_tree_count;
	map<unsigned long long, unsigned long long> fenwick_tree_quality[3];
	void add(unsigned long long s, long double value, int quality);
	query_ans get_sum(unsigned long long f);
	query_ans get_sum (timestamp tmp, bool include_last);

	public:
		void add (data_point tmp);
		pair<long double, int> get_sum(timestamp l, timestamp r, type_error errnom);
};

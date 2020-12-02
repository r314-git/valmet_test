#include "fenwick_tree.h"



void fenwick_tree::add(unsigned long long s, long double value, int quality)
{
	//log(LOCATION);
	
	for(unsigned long long i = s; i < MAXTIME; i = i | (i + 1))
		{
			if(quality == 0)
			{
				fenwick_tree_value[i] += value; 
				fenwick_tree_count[i] ++;
			}	
			fenwick_tree_quality[quality][i] ++;
		}
}

query_ans fenwick_tree::get_sum(unsigned long long f)
{
	//log(LOCATION);
	query_ans res;
	for(unsigned long long i = f; i > 0; i --)
		{
			res.sum_value += fenwick_tree_value[i]; 
			res.n += fenwick_tree_count[i]; 
			for(int t = 0; t < 3; t ++)
				res.quality[t] += fenwick_tree_quality[t][i];
			i = i & (i + 1);
			if(i == 0)
				break; 
		}
	return res;
}
query_ans fenwick_tree::get_sum(timestamp tmp, bool include_last)
{
	query_ans res;
	unsigned long long time_nano_sec = tmp.s * ten_9 + tmp.ns;
	if(!include_last){
		if(time_nano_sec == 0)
			return res;
		else
			time_nano_sec --;
	}
	return get_sum(time_nano_sec);
}

void fenwick_tree::add (data_point tmp)
{
	//log(LOCATION);
	
	unsigned long long time_nano_sec = tmp.ts.s * ten_9 + tmp.ts.ns;
	add(time_nano_sec, tmp.value, tmp.quality);
}

type_error fenwick_tree::get_sum(timestamp l, timestamp r, data_point &result)
{	
	type_error errnom = success;
	query_ans res_l = get_sum(l, false);
	query_ans res_r = get_sum(r, true);
	long double av = (res_r.sum_value - res_l.sum_value) / (1.0 * res_r.n - res_l.n);
	int worst_quality = 0;
	for(int t = 0; t < 3; t ++)
	{
		if(res_r.quality[t] - res_l.quality[t] > 0)
			worst_quality = t; 
	}
	if(res_r.n - res_l.n == 0)
	{
		errnom = zero_data_points_in_interval;
		log_error(errnom, LOCATION);
		return errnom;
	}
	result = data_point(l, av, worst_quality); 

	return success;

}
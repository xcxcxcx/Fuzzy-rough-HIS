//计算fuzzy rough的上近似
#include"upper_approximations.h"
#include <algorithm>
#include<iostream>

void upper_approximations(Sample &newx, std::vector<Sample> &nearestsample, int k, string temp, std::vector<vector <double>> &RG)
{
	std::vector<double> t_norm(k);

	for (int i = 0; i < k; i++)
	{
		if (nearestsample[i].label.compare(temp) == 0)
		{
			//计算t蕴含算子，t(x,y) = min(x,y)
			t_norm[i] = RG[newx.location][nearestsample[i].location];
		}
	}
	//取计算后的上确界
	double max = t_norm[0];
	for (int i = 0; i < k; i++)
	{
		if (t_norm[i] >= max)
		{
			max = t_norm[i];
		}
	}
		//赋值给待分类对象的上近似
		newx.upper_approximations = max;
}
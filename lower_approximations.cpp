//计算fuzzy rough的下近似

#include"lower_approximations.h"
#include <algorithm>
#include<iostream>
#include<time.h>

void lower_approximations(Sample &newx, std::vector<Sample> &nearestsample,int k, string temp, std::vector<vector <double>> &RG)
{
	std::vector<double> l_norm(k);

	for (int i = 0; i < k; i++)
	{
		
		if (nearestsample[i].label.compare(temp) != 0)
		{
			l_norm[i] = RG[newx.location][nearestsample[i].location];
		}
	}

	double max = l_norm[0];
	for (int i = 0; i < k; i++)
	{
		if (l_norm[i] >= max)
		{
			max = l_norm[i];
		}
	}

		//赋值给待分类对象的下近似
		newx.lower_approximations = sqrt(1 - pow(max,2));
}
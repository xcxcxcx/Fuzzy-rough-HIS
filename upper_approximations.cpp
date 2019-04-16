//����fuzzy rough���Ͻ���
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
			//����t�̺����ӣ�t(x,y) = min(x,y)
			t_norm[i] = RG[newx.location][nearestsample[i].location];
		}
	}
	//ȡ��������ȷ��
	double max = t_norm[0];
	for (int i = 0; i < k; i++)
	{
		if (t_norm[i] >= max)
		{
			max = t_norm[i];
		}
	}
		//��ֵ�������������Ͻ���
		newx.upper_approximations = max;
}
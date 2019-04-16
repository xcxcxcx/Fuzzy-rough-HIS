#include"dataprocess.h"
#include<iostream>
#include<fstream>
#include<set>
#include<ostream>
#include"get_vd.h"
#include"get_standard_deviation.h"

void dataprocess(std::vector<Sample>&testdata, std::vector<vector <double>> &RG)
{
	int m = testdata.size();
	int n = testdata[0].X.size();
	//int flag[] = { 1,4,3,1,1,4,3,1,4,1,3,1,3 };
	int flag[] = { //1,3, 4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,4
					1,1,1};


	std::vector<double>standard_deviation(n, 0);
	get_standard_deviation(testdata, standard_deviation, flag, m, n);

	for (int k = 0; k < n; k++)
	{
		bool pre_finish = false;
		std::map<double, int> single_attribute_count;
		std::map<double, std::map<std::string, int >> attribute_to_label_count;
		std::set<std::string> label_distinct;
		for (int i = 0; i < m; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				//vda += get_vd(testdata, i, j, k, flag[k], standard_deviation);
				RG[i][j] += pow(get_vd(testdata, i, j, k, flag[k], standard_deviation, pre_finish,single_attribute_count, attribute_to_label_count, label_distinct),2);
				//cout << vda << endl;
			}
			//RG[i][j] = RG[j][i] = exp(-totalvda / 1.6);
			//cout << RG[i][j] << endl;
		}
	}
	for (int i = 0; i < m; i++)
	{
		RG[i][i] = 1;
		for (int j = i + 1; j < m; j++)
		{	
			RG[i][j] = exp(-RG[i][j] / 1.6);
			RG[j][i] = RG[i][j];
		}
	}
}

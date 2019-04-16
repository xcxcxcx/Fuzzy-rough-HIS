#include"dataprocess.h"
#include<iostream>
#include<fstream>
#include<set>
#include<ostream>
#include"get_vd.h"
#include"get_standard_deviation.h"

void dataprocess(std::vector<Sample>&testdata, std::vector<vector <double>> &RG,int index)
{
	int m = testdata.size();
	int n = testdata[0].X.size();
	//int flag[] = { 1,4,3,1,1,4,3,1,4,1,3,1,3 };

	//*****************************************************************************
	/*int *pointer_flag[60];
	breast:3，3，3，4，3，3，3，4, 3
	cleveland : 1，3，3，1，1，4，3，1，4，1，3，1，3
	der：1，1，1，1，1，1，1，1，1，1，4，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1，1
	hepatitis : 1，3，4，4，4，4，4，4，4，4，4，4，4，1，1，1，1，1，4
	horse : 4，3，1，1，1，3，3，3，3，3，3，3，3，3，1，3，3，1，1，3，1，3
	risk : 1，1，1，1，4，1，1，4，1，4，1，4，1，4，4，4，4，4，4，4，4，4，4，4，4，1，1，1，4，4，4，4，4，4，4，4*/
	int *pointer_flag[3];
	int flag0[4] = {1,1,1,1};
	int flag1[3] = { 1,1,1 };
	int flag2[4] = { 1,1,1,1};
	pointer_flag[0] = flag0;
	pointer_flag[1] = flag1;
	pointer_flag[2] = flag2;
	//*****************************************************************************


	std::vector<double>standard_deviation(n, 0);
	//get_standard_deviation(testdata, standard_deviation, flag, m, n);                   2018.   8-10
	get_standard_deviation(testdata, standard_deviation, pointer_flag[index], m, n);

	//--------------------------------------------------------------------------------
	double vd;

	//--------------------------------------------------------------------------------
	for (int k = 0; k < n; k++)
	{
		vector<vector <double>> VdMetrix(m, vector<double>(m, 0));
		bool pre_finish = false;
		std::map<double, int> single_attribute_count;
		std::map<double, std::map<std::string, int >> attribute_to_label_count;
		std::set<std::string> label_distinct;
		for (int i = 0; i < m; i++)
		{
			bool find = false;
		//	if (i != 0)
		//	{
				for (int s = 0; s < i; s++)
				{
					if (testdata[i].X[k] == testdata[s].X[k])
					{
						find = true;
						for (int j = i + 1; j < m; j++)
						{
							VdMetrix[i][j] = VdMetrix[s][j];
							RG[i][j] += pow(VdMetrix[i][j], 2);
						}
						break;
					}
				}
				if (!find)
				{
					for (int j = i + 1; j < m; j++)
					{
						//RG[i][j] += pow(get_vd(testdata, i, j, k, flag[k], standard_deviation, pre_finish,single_attribute_count, attribute_to_label_count, label_distinct),2);
						//vd = get_vd(testdata, i, j, k, flag[k], standard_deviation, pre_finish, single_attribute_count, attribute_to_label_count, label_distinct);        2018.8.10
						vd = get_vd(testdata, i, j, k, pointer_flag[index][k], standard_deviation, pre_finish, single_attribute_count, attribute_to_label_count, label_distinct);
						VdMetrix[i][j] = vd;
						RG[i][j] += pow(VdMetrix[i][j], 2);
					}
				}
		//	}
		/*	else if(!find)
			{
				for (int j = i + 1; j < m; j++)
				{
					//RG[i][j] += pow(get_vd(testdata, i, j, k, flag[k], standard_deviation, pre_finish,single_attribute_count, attribute_to_label_count, label_distinct),2);
					vd = get_vd(testdata, i, j, k, flag[k], standard_deviation, pre_finish, single_attribute_count, attribute_to_label_count, label_distinct);
					VdMetrix[i][j] = vd;
					RG[i][j] += pow(VdMetrix[i][j], 2);
				}
			}*/
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

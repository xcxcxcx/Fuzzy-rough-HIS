#include"get_standard_deviation.h"
#include<iostream>

void get_standard_deviation(std::vector<Sample>&testdata, std::vector<double>&standard_deviation, int flag[], int m, int n)
{
	double standard_value;
	double total;
	double average;
	int question;
	for (int k = 0; k < n; k++)
	{
		total = 0;
		average = 0;
		question = 0;
		standard_value = 0;
		if (flag[k] == 1)
		{
			for (int i = 0; i < m; i++)
			{
				if (testdata[i].X[k] == -0.123456)
				{
					question++;
				}
				else
				{
					total += testdata[i].X[k];
				}
			}

			average = total / (m - question);

			for (int i = 0; i < m; i++)
			{
				if (testdata[i].X[k] == -0.123456)
				{
					;//NONE;
				}
				else
				{
					standard_value += pow(testdata[i].X[k] - average, 2);
				}

			}
			standard_deviation[k] = sqrt(standard_value / (m - question));
			//std::cout <<"the k is  "<<k<< " ,and the bzc is " << standard_deviation[k] << endl;
		}
	}
}
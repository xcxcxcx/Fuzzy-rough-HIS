#include"frnn.h"
#include"label_.h"
#include"similarity.h"
#include"calmembership.h"
#include"lower_approximations.h"
#include"upper_approximations.h"
#include"Sample.h"
#include"cmp.h"
#include"split.h"
#include"dataprocess.h"
#include <iostream>
#include <algorithm>

void frnn(Sample &newx, std::vector<Sample> &traindata, string &maxval, int fea, int k, std::vector<vector <double>> &RG)
{
	
	std::map<string, int> label_class;
	

	//label集合
	label_(traindata, label_class);
	//计算相似度
	similarity(traindata,newx, fea);
	//按相似度排序
	sort(traindata.begin(), traindata.end(), cmp);

	std::vector<Sample> nearestsample(k);
	for (int p = 0; p < k; p++)
	{
		nearestsample[p] = traindata[p];          //将前K个最相似样本存进vector<Sample> nearestsample
	}


	/*std::vector<double> l_norm(k);*/
	/*std::vector<double> t_norm(k);*/
	double T = 0;
	double pre;
	string temp;
	for (map<string, int>::iterator i = label_class.begin(); i != label_class.end(); i++)
	{
		//将当前label赋值给temp
		temp = i->first;                           
		//计算隶属度
		//calmembership(nearestsample, temp);

		//下近似
		lower_approximations(newx, nearestsample, k, temp,RG);

		//cout << "the lower is " << newx.lower_approximations << endl;
		//上近似
		upper_approximations(newx, nearestsample, k, temp,RG);

		//cout << "the upper is " << newx.upper_approximations << endl;
		//计算上下近似平均值
		pre = (newx.lower_approximations + newx.upper_approximations) / 2;
		if (pre >= T)
		{
			T = pre;
			maxval = i->first;
		}
	}
}
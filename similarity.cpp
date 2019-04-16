#include"similarity.h"

void similarity(std::vector<Sample> &traindata,Sample newx,int fea)
{
	int m = traindata.size();
	int n = traindata[0].X.size();
	std::vector<double> molecular(fea);
	std::vector<double> denominator(fea);
	std::vector<double> singlesimilarty(fea);
	std::vector<double> max_(fea, -10000);
	std::vector<double> min_(fea, 10000);

	for (int i = 0; i < m; i++)						//遍历训练集
	{
		for (int j = 0; j < n; j++)					//遍历训练集中的对象的属性
		{
			if (traindata[i].X[j] >= max_[j])
				max_[j] = traindata[i].X[j];		//将整个训练集中，每列属性最大值存在max_[]当中
			if (traindata[i].X[j] <= min_[j])
				min_[j] = traindata[i].X[j];		//将整个训练集中，每列属性最小值存在min_[]当中
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			molecular[j] = fabs(newx.X[j] - traindata[i].X[j]);         //求待分类对象和训练集对象的相同属性相减的绝对值
			denominator[j] = fabs(max_[j] - min_[j]);					//属性最大值和属性最小值的差
			singlesimilarty[j] = 1 - (molecular[j] / denominator[j]);	//求某个属性的相似度
		}																//公式：Ra(x,y) = 1 - (|a(x) - a(y)| / (|a_max - a_min|))
		double min = singlesimilarty[0];
		for (int i = 0; i < fea; i++)
		{
			if (singlesimilarty[i] <= min)
			{
				min = singlesimilarty[i];
			}
		}
		traindata[i].similarity = min;								//将属性相似度最小的赋值给样本相似度
	}
}
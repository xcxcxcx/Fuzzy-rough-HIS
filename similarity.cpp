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

	for (int i = 0; i < m; i++)						//����ѵ����
	{
		for (int j = 0; j < n; j++)					//����ѵ�����еĶ��������
		{
			if (traindata[i].X[j] >= max_[j])
				max_[j] = traindata[i].X[j];		//������ѵ�����У�ÿ���������ֵ����max_[]����
			if (traindata[i].X[j] <= min_[j])
				min_[j] = traindata[i].X[j];		//������ѵ�����У�ÿ��������Сֵ����min_[]����
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			molecular[j] = fabs(newx.X[j] - traindata[i].X[j]);         //�����������ѵ�����������ͬ��������ľ���ֵ
			denominator[j] = fabs(max_[j] - min_[j]);					//�������ֵ��������Сֵ�Ĳ�
			singlesimilarty[j] = 1 - (molecular[j] / denominator[j]);	//��ĳ�����Ե����ƶ�
		}																//��ʽ��Ra(x,y) = 1 - (|a(x) - a(y)| / (|a_max - a_min|))
		double min = singlesimilarty[0];
		for (int i = 0; i < fea; i++)
		{
			if (singlesimilarty[i] <= min)
			{
				min = singlesimilarty[i];
			}
		}
		traindata[i].similarity = min;								//���������ƶ���С�ĸ�ֵ���������ƶ�
	}
}
#include"label_.h"

void label_(std::vector<Sample> &traindata,std::map<string, int> &label_class)
{
	for (std::vector<Sample>::iterator it = traindata.begin(); it != traindata.end(); it++)  //����ѵ�����е�label
	{
		label_class[it->label] = 1;					//��label�洢��label_class����
	}
}
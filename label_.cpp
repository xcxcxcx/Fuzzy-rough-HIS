#include"label_.h"

void label_(std::vector<Sample> &traindata,std::map<string, int> &label_class)
{
	for (std::vector<Sample>::iterator it = traindata.begin(); it != traindata.end(); it++)  //遍历训练集中的label
	{
		label_class[it->label] = 1;					//将label存储在label_class当中
	}
}
#include"calmembership.h"

void calmembership(std::vector<Sample> &nearestsample,string temp)
{
	for (std::vector<Sample>::iterator it = nearestsample.begin(); it != nearestsample.end(); it++)   //遍历最临近的K个样本
		{
			if (it->label == temp)			//若和传进来的label相等
				it->membership = 1;			//隶属度则为1
			else
				it->membership = 0;			//否则则为0
		}
}
#ifndef calmembership_h
#define calmembership_h

#include "Sample.h"

/*
nearestsample：前K个训练集样本
temp：数据集中的label
输出：将训练集中的样本的隶属度保存在前K个训练集中
*/

void calmembership(std::vector<Sample> &nearestsample,string temp);

#endif#

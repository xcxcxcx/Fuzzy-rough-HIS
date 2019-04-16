#ifndef upper_approximations_h
#define upper_approximations_h

#include "Sample.h"

/*
newx：待分类对象
nearestsample：k个近邻训练集
k：近邻样本的个数
输出：计算出当前样本的上近似
*/

void upper_approximations(Sample &newx, std::vector<Sample> &nearestsample, int k, string temp, std::vector<vector <double>> &RG);

#endif#

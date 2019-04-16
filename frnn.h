#ifndef frnn_h
#define frnn_h

#include "Sample.h"

/*
newx：待分类的对象
traindata：训练集
maxval：用来存储待分类对象的最大可能性分类
fea：属性值
k：近邻个数
输出：将最大可能性分类保存在maxval中
*/

void frnn(Sample &newx, std::vector<Sample> &traindata, string &maxval, int fea, int k, std::vector<vector <double>> &RG);

#endif#
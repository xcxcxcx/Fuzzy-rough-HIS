#ifndef label__h
#define label__h
#include"Sample.h"
//存储label种类
/*
traindata：训练集
label_class：用来保存当前训练集中的label的值
输出：将label种类保存在label_class中
*/

void label_(std::vector<Sample> &traindata, std::map<string, int> &label_class);

#endif#

#ifndef frnn_h
#define frnn_h

#include "Sample.h"

/*
newx��������Ķ���
traindata��ѵ����
maxval�������洢�����������������Է���
fea������ֵ
k�����ڸ���
��������������Է��ౣ����maxval��
*/

void frnn(Sample &newx, std::vector<Sample> &traindata, string &maxval, int fea, int k, std::vector<vector <double>> &RG);

#endif#
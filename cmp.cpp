#include"cmp.h"

bool cmp(Sample &s1, Sample &s2)
{
	return s1.similarity > s2.similarity;     //根据样本的相似度从高到低排序
}
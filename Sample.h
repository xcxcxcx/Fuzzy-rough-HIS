#ifndef Sample_h
#define Sample_h

#include<vector>
#include<string>
#include<map>
using namespace std;

class Sample
{
public:
	std::vector<double> X;//特征
	double similarity;//相似度
	double membership;//隶属度
	string label;//类别
	double lower_approximations;//下近似
	double upper_approximations;//上近似
	string result; //分类结果
	int location;
};

#endif

#ifndef Sample_h
#define Sample_h

#include<vector>
#include<string>
#include<map>
using namespace std;

class Sample
{
public:
	std::vector<double> X;//����
	double similarity;//���ƶ�
	double membership;//������
	string label;//���
	double lower_approximations;//�½���
	double upper_approximations;//�Ͻ���
	string result; //������
	int location;
};

#endif

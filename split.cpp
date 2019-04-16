#include"split.h"

//�ַ����ָ��
vector<string> split(string str, string pattern)
{
	vector<string> ret;												//����ָ�֮����ַ���
	if (pattern.empty())
		return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);		//��Ѱ�ַ����е�һ������pattern��λ��
	while (index != str.npos)										//������
	{
		if (start != index)											
			ret.push_back(str.substr(start, index - start));		//��startλ�ÿ�ʼ�ģ�����Ϊindex - start���ַ���push��ret��
		start = index + 1;											//�ı�startλ��
		index = str.find_first_of(pattern, start);					//������Ѱpattern���ֵ�λ��
	}
	if (!str.substr(start).empty())						
		ret.push_back(str.substr(start));							//���һ��pattern֮����ַ���Ҳ�Ž�ȥ
	return ret;
}
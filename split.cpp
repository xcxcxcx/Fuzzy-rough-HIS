#include"split.h"

//字符串分割函数
vector<string> split(string str, string pattern)
{
	vector<string> ret;												//保存分割之后的字符串
	if (pattern.empty())
		return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);		//找寻字符串中第一个出现pattern的位置
	while (index != str.npos)										//若存在
	{
		if (start != index)											
			ret.push_back(str.substr(start, index - start));		//将start位置开始的，长度为index - start的字符串push进ret中
		start = index + 1;											//改变start位置
		index = str.find_first_of(pattern, start);					//继续找寻pattern出现的位置
	}
	if (!str.substr(start).empty())						
		ret.push_back(str.substr(start));							//最后一个pattern之后的字符串也放进去
	return ret;
}
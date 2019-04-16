#include"getcol.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int getcol(const char *filename)
{
	char a[10000];
	FILE *file = fopen(filename, "r");       //打开文件
	if (!file)
	{
		cout << "找不到指定的文件" << endl;
		return -1;
	}

	fgets(a, 10000, file);
	int col = 0;
	for (int i = 0; i<10000; i++)
	{
		if (a[i] == ',')					//遇到逗号
		{
			col += 1;						//列数+1
		}
		if (a[i] == NULL)					//若为空（则是到了一行的末尾，列数=逗号的个数+1）
		{
			col += 1;						//列数+1
			break;							//跳出循环
		}
	}
	return col;								//返回列数
}
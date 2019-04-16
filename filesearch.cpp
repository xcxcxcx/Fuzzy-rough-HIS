#include"filesearch.h"
#include<io.h>

void filesearch(string path, std::vector<string> &fileIn)
{
	struct _finddata_t filefind;
	string curr = path + "*.*";                           //path:搜索路径 *.*：搜索条件  
	int done = 0, handle;
	if ((handle = _findfirst(curr.c_str(), &filefind)) != -1)
	{
		while (!(done = _findnext(handle, &filefind)))
		{
			if (strcmp(filefind.name, "..") == 0)
				continue;
			if ((_A_SUBDIR == filefind.attrib))              // 是目录  
			{
				//	cout<<"[Dir]:\t%s\n"cout<<filefind.name<<endl;
				curr = path + "\\" + filefind.name;
				filesearch(curr, fileIn);                  // 继续递归遍历子目录  
			}
			else
			{													//否则
				//	cout<<"[File]:\t%s\n"cout<<filefind.name<<endl;
				fileIn.push_back(filefind.name);			//将文件名称放入fileIn
			}
		}
		_findclose(handle);
	}
}
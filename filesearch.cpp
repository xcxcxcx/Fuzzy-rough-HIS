#include"filesearch.h"
#include<io.h>

void filesearch(string path, std::vector<string> &fileIn)
{
	struct _finddata_t filefind;
	string curr = path + "*.*";                           //path:����·�� *.*����������  
	int done = 0, handle;
	if ((handle = _findfirst(curr.c_str(), &filefind)) != -1)
	{
		while (!(done = _findnext(handle, &filefind)))
		{
			if (strcmp(filefind.name, "..") == 0)
				continue;
			if ((_A_SUBDIR == filefind.attrib))              // ��Ŀ¼  
			{
				//	cout<<"[Dir]:\t%s\n"cout<<filefind.name<<endl;
				curr = path + "\\" + filefind.name;
				filesearch(curr, fileIn);                  // �����ݹ������Ŀ¼  
			}
			else
			{													//����
				//	cout<<"[File]:\t%s\n"cout<<filefind.name<<endl;
				fileIn.push_back(filefind.name);			//���ļ����Ʒ���fileIn
			}
		}
		_findclose(handle);
	}
}
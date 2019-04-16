#include"loaddata.h"
#include"split.h"
#include<time.h>
#include<fstream>


int loaddata(std::vector<Sample> &traindata, std::vector<Sample> &testdata, std::vector<Sample> &alldata, const char *filename, int fold)
{
	srand((unsigned)time(NULL));
	int row = 0;
	Sample sample;
	string pattern = ",";
	fstream fin(filename);
	bool isInited = false;
	char* readline = (char*)malloc(2000);
	int location = 0;
	while (!fin.eof())
	{
		//һ��һ�ж�����
		fin.getline(readline, 2000, '\n');
		string a = readline;
		//	cout << readline << endl;;
		//��һ�����ݰ����ŷָ����ָ�ɼ��飬�洢��vector<string> splited��
		vector<string> splited = split(a, pattern);
		//�ж��ǲ��ǿ��У�����ǿ�������������ѭ��
		if (splited.size() == 0) continue;
		//����samle�Ĵ�С������Ӧ��ͬ��samle.X����
		if (sample.X.size() != splited.size() - 1)
		{
			int size = splited.size() - 1 - sample.X.size();		//���ָ���������Դ���sample.X�ĸ���
			if (size>0)
			{
				for (int i = 0; i<abs(size); i++)
					sample.X.push_back(0);							//��sample.X��������
			}
			else
			{
				for (int i = 0; i<abs(size); i++)
					sample.X.pop_back();							//��sample.X��������
			}
		}

	//	���ѭ������������,��result.size()==0��ʱ�򡣾ͻ�ȥ����samle.X[-1]����˵�ͷ�������
		for (unsigned int i = 0; i<(splited.size() - 1); i++)
		{
				sample.X[i] = atof(splited[i].c_str());
	
		}
		//for (unsigned int i = 0; i<(splited.size() - 1); i++)
		//{
		//	if (splited[i] == "?") {
		//		sample.X[i] = -0.123456; //��-0.123456���棿
		//	}
		//	else {
		//		sample.X[i] = atof(splited[i].c_str());
		//	}
		//}
		sample.location = location;
		//ȡlabel
		sample.label = *(splited.end() - 1);
		location++;

		alldata.push_back(sample);

		if (row % 10 == fold)
			//��һ�е����ݷ���trainDatas
			testdata.push_back(sample);
		else
			traindata.push_back(sample);
		row++;
		//	cout << "sample.X�ĳ��ȣ�" << sample.X.size() << "  " << sample.label << endl;
	}
	free(readline);
	return location;
}
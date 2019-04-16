
#include <iostream>
#include <time.h> 
#include <fstream> 
#include"getcol.h"
#include"loaddata.h"
#include"frnn.h"
#include"filesearch.h"
#include"dataprocess.h"
#include"get_vd.h"
#include<windows.h>
using namespace std;


int main()
{
	int kfold = 10;                                      //ͬ����Kֵ��һ���ظ�����kfold��
	double accurarytmp = 0;                               //�洢ƽ����ȷ��
	string maxval;                                        //��������ܵ�label
	int col = 0;											//�������
	std::vector<string> fileIn;								//����ļ����µ��ļ�
	string path = "D:\\pythontest\\data3\\";			//�ļ���·��
	filesearch(path, fileIn);								//���ļ��µ��ļ�ȫ�������fileIn��
	string store = "D:\\pythontest\\bbb\\";			//���ʵ����

	//for(int i = 0; i < fileIn.size(); i++)  // ѭ�������ļ��µ����ݼ�
	//{ 
		string absolute_path = path + fileIn[0];   //��ĳ�����ݼ��ĵ�ַ
		string store_path = store + fileIn[0];   //��ŵ�ĳ�����ݼ��ĵ�ַ
		//cout << absolute_path << " "<< store_path << endl;
		col = getcol(absolute_path.c_str());
		int fea = col - 1;

		std::vector<Sample> traindata, testdata, alldata;
		int location = loaddata(traindata, testdata, alldata, absolute_path.c_str(),0);      //װ������
		vector<vector <double>> RG(location, vector<double>(location,0));

		clock_t start1, finish1;
		start1 = clock();
		dataprocess(alldata, RG);
		finish1 = clock();
		double time1 = (finish1 - start1);
		ofstream outFile;

		outFile.open(store_path, ios::out | ios::app);					//�򿪴洢λ���ļ�
		outFile << "process" << "," << time1 << endl;					//��kֵ�ͷ���ɹ��ĸ���д��

		outFile.close();											//�ر��ļ�

		std::cout << "data process ok!" << endl;

		for (int k = 1; k < 41; k++)
		{
			clock_t start, finish;
			start = clock();
			for (int fold = 0; fold < kfold; fold++)
			{
				std::vector<Sample> traindata, testdata, alldata;
				int location = loaddata(traindata, testdata,alldata, absolute_path.c_str(), fold);      //װ������

				double matched = 0;                                //�������ɹ�������
				double accurary = 0;								//���浥�γɹ���
				int num = testdata.size();
				for (int i = 0; i < num; i++)
				{
					frnn(testdata[i], traindata, maxval, fea, k,RG);			//�õ��������Ե�label

					testdata[i].result = maxval;						//���������Ե�label��ֵ��result

					if (testdata[i].label == testdata[i].result)		//���result�ͱ�����labelһ������ô����ɹ�
						matched += 1;									//����ɹ����� +1
					//std::cout << "the real is  " << testdata[i].label << " " << "the pre is  " << testdata[i].result << endl;
				}
				accurary = matched / num;									//�ɹ�����/��ǰ��������������= ����ɹ���
				//cout << "--------------------------------------------" << endl
				//cout << "the accurary is " << accurary << endl;
			//	Sleep(500);
				accurarytmp += accurary;									//��kfold�εĳɹ��ʼ�����
				
		}
			accurarytmp = accurarytmp / kfold;								//����ٳ���fold��  ����ƽ���ɹ���
			//std::cout <<"k is "<<k<< " the totalaccurary is " << accurarytmp << endl;	//��ӡ����
			finish = clock();
			double time = (finish - start);
			ofstream outFile;

			outFile.open(store_path, ios::out | ios::app);					//�򿪴洢λ���ļ�
			outFile << k << "," << accurarytmp << "," << "time" << "," << time << endl;					//��kֵ�ͷ���ɹ��ĸ���д��

			outFile.close();											//�ر��ļ�

			accurarytmp = 0;												//���³�ʼ��Ϊ0
		}
	
		//	cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		//ofstream outFile;

		//outFile.open(store_path, ios::out | ios::app);					//�򿪴洢λ���ļ�
		//outFile << "time" << "," << time << endl;						//��kֵ�ͷ���ɹ��ĸ���д��

		//outFile.close();
	//}

	return 0;
}
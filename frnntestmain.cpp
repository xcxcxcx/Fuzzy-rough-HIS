
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
	int kfold = 10;                                      //同样的K值，一共重复运行kfold次
	double accurarytmp = 0;                               //存储平均正确率
	string maxval;                                        //存放最大可能的label
	int col = 0;											//存放列数
	std::vector<string> fileIn;								//存放文件夹下的文件
	string path = "D:\\pythontest\\data3\\";			//文件夹路径
	filesearch(path, fileIn);								//将文件下的文件全部存放在fileIn中
	string store = "D:\\pythontest\\bbb\\";			//存放实验结果

	//for(int i = 0; i < fileIn.size(); i++)  // 循环遍历文件下的数据集
	//{ 
		string absolute_path = path + fileIn[0];   //第某个数据集的地址
		string store_path = store + fileIn[0];   //存放第某个数据集的地址
		//cout << absolute_path << " "<< store_path << endl;
		col = getcol(absolute_path.c_str());
		int fea = col - 1;

		std::vector<Sample> traindata, testdata, alldata;
		int location = loaddata(traindata, testdata, alldata, absolute_path.c_str(),0);      //装载数据
		vector<vector <double>> RG(location, vector<double>(location,0));

		clock_t start1, finish1;
		start1 = clock();
		dataprocess(alldata, RG);
		finish1 = clock();
		double time1 = (finish1 - start1);
		ofstream outFile;

		outFile.open(store_path, ios::out | ios::app);					//打开存储位置文件
		outFile << "process" << "," << time1 << endl;					//将k值和分类成功的概率写入

		outFile.close();											//关闭文件

		std::cout << "data process ok!" << endl;

		for (int k = 1; k < 41; k++)
		{
			clock_t start, finish;
			start = clock();
			for (int fold = 0; fold < kfold; fold++)
			{
				std::vector<Sample> traindata, testdata, alldata;
				int location = loaddata(traindata, testdata,alldata, absolute_path.c_str(), fold);      //装载数据

				double matched = 0;                                //保存分类成功的数量
				double accurary = 0;								//保存单次成功率
				int num = testdata.size();
				for (int i = 0; i < num; i++)
				{
					frnn(testdata[i], traindata, maxval, fea, k,RG);			//得到最大可能性的label

					testdata[i].result = maxval;						//将最大可能性的label赋值给result

					if (testdata[i].label == testdata[i].result)		//如果result和本来的label一样，那么分类成功
						matched += 1;									//分类成功数量 +1
					//std::cout << "the real is  " << testdata[i].label << " " << "the pre is  " << testdata[i].result << endl;
				}
				accurary = matched / num;									//成功数量/当前分类样本的总数= 分类成功率
				//cout << "--------------------------------------------" << endl
				//cout << "the accurary is " << accurary << endl;
			//	Sleep(500);
				accurarytmp += accurary;									//将kfold次的成功率加起来
				
		}
			accurarytmp = accurarytmp / kfold;								//最后再除以fold，  就是平均成功率
			//std::cout <<"k is "<<k<< " the totalaccurary is " << accurarytmp << endl;	//打印出来
			finish = clock();
			double time = (finish - start);
			ofstream outFile;

			outFile.open(store_path, ios::out | ios::app);					//打开存储位置文件
			outFile << k << "," << accurarytmp << "," << "time" << "," << time << endl;					//将k值和分类成功的概率写入

			outFile.close();											//关闭文件

			accurarytmp = 0;												//重新初始化为0
		}
	
		//	cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
		//ofstream outFile;

		//outFile.open(store_path, ios::out | ios::app);					//打开存储位置文件
		//outFile << "time" << "," << time << endl;						//将k值和分类成功的概率写入

		//outFile.close();
	//}

	return 0;
}
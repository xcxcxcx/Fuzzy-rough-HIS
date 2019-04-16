#include"get_vd.h"
#include"get_label_index.h"
#include<math.h>

void pre_vdm(std::vector<Sample> &data_set, int attribute_index, std::map<double, int> &single_attribute_count,
	std::map<double, std::map<std::string, int >> &attribute_to_label_count,std::set<std::string> &label_distinct) 
{
	for (unsigned int i = 0; i < data_set.size(); i++)
	{
		single_attribute_count[data_set[i].X[attribute_index]] += 1;
		label_distinct.insert(data_set[i].label);
	}

	for (unsigned int i = 0; i < data_set.size(); i++)
	{
		attribute_to_label_count[data_set[i].X[attribute_index]][data_set[i].label] ++;
	}
}

double xy_get_vdm(int attribute_value1, int attribute_value2, std::map<double, int> &single_attribute_count,
	std::map<double, std::map<std::string, int >> &attribute_to_label_count, std::set<std::string> &label_distinct) 
{
	int x1_count = single_attribute_count[attribute_value1];
	int x2_count = single_attribute_count[attribute_value2];
	int label_count = label_distinct.size();

	double sum = 0;
	for (int i = 0; i < label_count; i++) {
		int j = 0;
		string temp_label = "";
		for (std::set<std::string>::iterator itr = label_distinct.begin(); itr != label_distinct.end(); itr++, j++) {
			if (j == i) {
				temp_label = (*itr);
			}
		}

		double x1_label_count = attribute_to_label_count[attribute_value1][temp_label];
		double x2_label_count = attribute_to_label_count[attribute_value2][temp_label];

		sum += pow((x1_label_count / x1_count) - (x2_label_count / x2_count), 2);
	}

	double result = sqrt(1.0*sum / label_count);

	//cout << result;
	return result;
}

double get_vd(std::vector<Sample> &testdata, int index1, int index2, int attribute, int &flag, std::vector<double>&standard_deviation,
	bool pre_finish, std::map<double, int> &single_attribute_count, std::map<double, std::map<std::string, int >> &attribute_to_label_count,
	std::set<std::string> &label_distinct) {
	double x1 = testdata[index1].X[attribute];
	double x2 = testdata[index2].X[attribute];
	double result = 0;
	
	if (x1 == -0.123456 || x2 == -0.123456)
		result = 1;
	//vdr
	else if (flag == 1)
	{
		result = abs(x1 - x2) / (4 * standard_deviation[attribute]);
	}
	//vds
	/*else if (flag == 2)
	{

	}*/
	//vdm
	else if (flag == 3)
	{
		if (!pre_finish) {
			pre_vdm(testdata, attribute, single_attribute_count, attribute_to_label_count, label_distinct);
			pre_finish = true;
		}
		result = xy_get_vdm(x1, x2, single_attribute_count, attribute_to_label_count, label_distinct);
	}
	//vdb
	else if (flag == 4)
	{
		if (x1 == x2)
		{
			result = 0;
		}
		else
		{
			result = 1;
		}
	}

	return  result;
}
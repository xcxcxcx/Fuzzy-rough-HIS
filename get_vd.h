#ifndef get_vd_h
#define get_vd_h
#include<set>

#include "Sample.h"
double get_vd(std::vector<Sample> &testdata, int index1, int index2, int attribute, int &flag, std::vector<double>&standard_deviation,
	bool pre_finish, std::map<double, int> &single_attribute_count, std::map<double, std::map<std::string, int >> &attribute_to_label_count,
	std::set<std::string> &label_distinct);

#pragma once
#endif#
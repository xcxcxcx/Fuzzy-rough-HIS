#include"get_label_index.h"

int get_label_index(std::set<std::string> label_distinct, std::string label) 
{
	int i = 0;
	for (std::set<std::string>::iterator itr = label_distinct.begin(); itr != label_distinct.end(); itr++, i++) {
		if ((*itr).compare(label) == 0) {
			return i;
		}
	}
}
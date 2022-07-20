#include <iostream>
#include <string>
#include "Split.h"

vector<string> Split::Split(string input, const char delim) {
	int len = input.length();
	vector<string> ans;
	for (int i = 0; i < len; ) {
		int spacei = input.find(delim, i);

		//找到最后一个单词
		if (spacei == -1) {
			spacei = len;
		}

		string temp = input.substr(i, spacei - i);
		ans.push_back(temp);
		i = spacei + 1;
	}

	return ans;
}
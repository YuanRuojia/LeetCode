#include <iostream>
#include <string>
#include "ListFunction.h"

vector<string> ListFunction::Split(string input, const char delim) {
	int len = input.length();
	vector<string> ans;
	for (int i = 0; i < len; ) {
		int spacei = input.find(delim, i);

		//找到最后一个单词
		if (spacei == -1) {
			spacei = len;
		}

		string temp = input.substr(i, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(spacei) - i);
		ans.push_back(temp);
		i = spacei + 1;
	}

	return ans;
}

MyList* ListFunction::ListMerge(MyList* A, MyList* B) {
	ListNode* Pa = A->GetList()->next;
	ListNode* Pb = B->GetList()->next;

	MyList* merged = new MyList;
	vector<string> datas;

	while (Pa != NULL && Pb != NULL) {
		if (Pa->data < Pb->data) {
			datas.push_back(Pa->data);
			Pa = Pa->next;
		}
		else {
			datas.push_back(Pb->data);
			Pb = Pb->next;
		}
	}

	if (Pa) {
		while (Pa != NULL) {
			datas.push_back(Pa->data);
			Pa = Pa->next;
		}
	}
	if (Pb) {
		while (Pb != NULL) {
			datas.push_back(Pb->data);
			Pb = Pb->next;
		}
	}

	merged->BackCreate(datas);
	delete A;
	delete B;

	return merged;
}

MyList* ListFunction::KListMerge(vector<MyList*> Lists) {
	return NULL;
}
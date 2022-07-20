#include <iostream>
#include "MyList.h"

void MyList::HeadCreate() {
	cout << "请输入节点，使用空格隔开:" << endl;
	string input;
	getline(cin, input);
	vector<string> nodes = Split::Split(input, ' ');

	List L = new ListNode;

}

void MyList::BackCreate() {

}

void MyList::ReverseList() {

}
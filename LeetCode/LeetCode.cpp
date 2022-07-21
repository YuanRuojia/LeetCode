#include <iostream>
#include "Btree.h"
#include "ThreadBTree.h"
#include "T731.h"
#include "MyList.h"
#include "ListFunction.h"

using namespace std;

int main()
{
	/*Btree* btree = new Btree;
	btree->test();*/

	/*ThreadBTree* tbtree = new ThreadBTree;
	tbtree->test();*/

	/*T731* time = new T731;
	time->test();*/

	/*string input;
	getline(cin, input);

	vector<string> ans = Split::Split(input, ' ');
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}*/

	MyList* list = new MyList;
	list->BackCreate();

	int start;
	int end;
	cout << "请输入需要反转的组长度：" << endl;
	cin >> start;
	list->reverseKGroup(start);
	list->Output();
}

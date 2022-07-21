#include <iostream>
#include "Btree.h"
#include "ThreadBTree.h"
#include "T731.h"
#include "MyList.h"

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

	MyList* listA = new MyList;
	listA->BackCreate();
	MyList* listB = new MyList;
	listB->BackCreate();
	MyList* listC = new MyList;
	listC->BackCreate();

	vector<MyList*> lists;
	lists.push_back(listA);
	lists.push_back(listB);
	lists.push_back(listC);
	MyList* list = MyList::KListMerge(lists);
	
	list->Output();
}

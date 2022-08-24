#include <iostream>
//#include "Btree.h"
//#include "ThreadBTree.h"
//#include "T731.h"
//#include "MyList.h"
//#include "smartptr.h"
#include "smartList.h"
#include "D86T1.h"
#include "D807.h"
#include "L1656.h"
#include "L876.h"
#include "L121.h"
#include "L409.h"

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

	/*MyList* listA = new MyList;
	listA->BackCreate();
	listA->deleteDuplicates();
	listA->Output();*/

	/*smartptr::smartptrtest();*/

	/*shared_ptr<smartList<int>> intsl(new smartList<int>);
	intsl->backcreate();
	intsl->show();

	shared_ptr<smartList<string>> strsl = make_shared<smartList<string>>();
	strsl->backcreate();
	strsl->show();*/

	//vector<int> tasks = { 1,2,1,2,3,1 };
	//D86T1::taskSchedulerII(tasks, 3);

	/*vector<int> tasks = { 0,1,4,6,7,10 };
	D807::arithmeticTriplets(tasks, 3);*/

	//[3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]
	/*L1656* test = new L1656(5);
	test->insert(3, "ccccc");
	test->insert(1, "aaaaa");
	test->insert(2, "bbbbb");
	test->insert(5, "eeeee");
	test->insert(4, "ddddd");*/

	/*L876::TEST();*/

	/*L121* test = new L121();
	delete(test);*/

	cout << L409::longestPalindrome("abccccdd") << endl;

	return 0;
}
/*
1 2 3 4 5

*/
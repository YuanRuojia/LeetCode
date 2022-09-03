#include <iostream>
//#include "Btree.h"
//#include "ThreadBTree.h"
//#include "T731.h"
//#include "MyList.h"
//#include "smartptr.h"
//#include "smartList.h"
//#include "D86T1.h"
//#include "D807.h"
//#include "L1656.h"
//#include "L876.h"
//#include "L121.h"
//#include "L409.h"
//#include "BinarySearch.h"
//#include "L733.h"
//#include "L746.h"
//#include "L62.h"
//#include "L202.h"
//#include "L54.h"
#include "L14.h"

using namespace std;

int main()
{
	//Btree* btree = new Btree;
	//btree->CreateBTree();
	//BiTNode* p = new BiTNode;
	//p->data = "0";
	//BiTNode* q = new BiTNode;
	//q->data = "5";

	//cout << btree->lowestCommonAncestor(btree->Getroot(), p, q)->data;

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

	/*cout << L409::longestPalindrome("abccccdd") << endl;*/

	/*vector<int> input;
	int tar;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input.emplace_back(temp);
	}
	cin >> tar;
	cout<<BinarySearch::search(input, tar);*/

	/*L733* test = new L733;
	test->test();*/

	/*vector<int> testcase = {1,100,1,1,1,100,1,1,100,1};
	cout<<L746::minCostClimbingStairs(testcase);*/

	//cout << L62::uniquePaths(3, 7);

	//cout << L202::isHappy(19);

	/*vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	L54* test = new L54;
	test->spiralOrder(matrix);*/

	vector<string> input = { "dog","racecar","car" };
	cout << L14::longestCommonPrefix(input);

	return 0;
}
/*
1 2 3 4 5

*/
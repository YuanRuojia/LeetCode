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
#include "L2131.h"
#include "L621.h"
#include "L1592.h"
#include "L108.h"
#include "L417.h"
#include "L43.h"

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

	/*vector<string> input = { "dog","racecar","car" };
	cout << L14::longestCommonPrefix(input);*/

	/*vector<string> input = { "ab","ty","yt","lc","cl","ab" };
	cout << L2131::longestPalindrome(input);*/

	/*vector<char> input = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	cout << L621::leastInterval(input, 2);*/

	//cout << L1592::reorderSpaces("  this   is  a sentence ");

	/*vector<vector<int>> map = { {8,13,11,18,14,16,16,4,4,8,10,11,1,19,7},{2,9,15,16,14,5,8,15,9,5,14,6,10,15,5},{15,16,17,10,3,6,3,4,2,17,0,12,4,1,3},{13,6,13,15,15,16,4,10,7,4,19,19,4,9,13},{7,1,9,14,9,11,5,4,15,19,6,0,0,13,5},{9,9,15,12,15,5,1,1,18,1,2,16,15,18,9},{13,0,4,18,12,0,11,0,1,15,1,15,4,2,0},{11,13,12,16,9,18,6,8,18,1,5,12,17,13,5},{7,17,2,5,0,17,9,18,4,13,6,13,7,2,1},{2,3,9,0,19,6,6,15,14,4,8,1,19,5,9},{3,10,5,11,7,14,1,5,3,19,12,5,2,13,16},{0,8,10,18,17,5,5,8,2,11,5,16,4,9,14},{15,9,16,18,9,5,2,5,13,3,10,19,9,14,3},{12,11,16,1,10,12,6,18,6,6,18,10,9,5,2},{17,9,6,6,14,9,2,2,13,13,15,17,15,3,14},{18,14,12,6,18,16,4,10,19,5,6,8,9,1,6} };
	L417* test = new L417;
	test->pacificAtlantic(map);
	cout << "done";*/

	L43* test = new L43;
	cout << test->multiply("123", "456");

	
	return 0;
}
/*
1 2 3 4 5

*/
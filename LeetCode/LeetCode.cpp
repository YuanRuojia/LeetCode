#include <iostream>
#include "Btree.h"

using namespace std;

int main()
{
	Btree* Tree = new Btree;
	Tree->CreateBTree();

	cout << "递归：" << endl;
	Tree->RecrusionNLR();   cout << endl;
	Tree->RecrusionLNR();	cout << endl;
	Tree->RecrusionLRN();	cout << endl;

	cout << "非递归：" << endl;
	Tree->nonRecrusionNLR();	cout << endl;
	Tree->nonRecrusionLNR();	cout << endl;
	Tree->nonRecrusionLRN();	cout << endl;

	cout << "层序：" << endl;
	Tree->LevelOrder();		cout << endl;
}

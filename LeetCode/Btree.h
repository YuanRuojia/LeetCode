#pragma once
#ifndef BTREE_H_
#define BTREE_H_

#include <stack>
#include <queue>

using namespace std;

typedef struct BiTNode {
	string data;
	struct BiTNode* Lchild;
	struct BiTNode* Rchild;
}BiTNode, * BiTree;

class Btree
{
private:
	BiTree tree;

public:
	void CreateBTree();

	//µ›πÈ±È¿˙
	void RecrusionNLR() const;
	void RecrusionLNR() const;
	void RecrusionLRN() const;

	//∑«µ›πÈ±È¿˙
	void nonRecrusionNLR() const;
	void nonRecrusionLNR() const;
	void nonRecrusionLRN() const;

	//≤„–Ú±È¿˙
	void LevelOrder() const;
};

#endif // !BTREE_H_
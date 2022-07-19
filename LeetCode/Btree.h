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

	//�ݹ����
	void RecrusionNLR() const;
	void RecrusionLNR() const;
	void RecrusionLRN() const;

	//�ǵݹ����
	void nonRecrusionNLR() const;
	void nonRecrusionLNR() const;
	void nonRecrusionLRN() const;

	//�������
	void LevelOrder() const;
};

#endif // !BTREE_H_
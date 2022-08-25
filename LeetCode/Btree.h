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
	void test();
	BiTNode* Getroot();

	//递归遍历
	void RecrusionNLR() const;
	void RecrusionLNR() const;
	void RecrusionLRN() const;

	//非递归遍历
	void nonRecrusionNLR() const;
	void nonRecrusionLNR() const;
	void nonRecrusionLRN() const;

	//层序遍历
	void LevelOrder() const;

	//最近公共祖先
	BiTNode* lowestCommonAncestor(BiTNode* root, BiTNode* p, BiTNode* q);
	
	//寻路
	vector<BiTNode*> DFS(BiTree root, BiTNode* tar);
};

#endif // !BTREE_H_
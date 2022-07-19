#pragma once
#ifndef THREADBTREE_H_
#define THREADBTREE_H_

#include <iostream>
#include <string>

using namespace std;

typedef struct ThreadBTNode {
	string data;
	struct ThreadBTNode* Lchild;
	struct ThreadBTNode* Rchild;
	bool Ltag;
	bool Rtag;
}ThreadBTNode, * TBTree;

class ThreadBTree
{
private:
	TBTree tbtree;

public:
	void CreateTBTree();
	void test();

	//线索化
	void CreatePreThread();
	void CreateInThread();
	void CreatePostThread();

	//遍历线索二叉树
	void Pretraversal() const;
	void Intraversal() const;
	void Posttraversal() const;
};

#endif THREADBTREE_H_
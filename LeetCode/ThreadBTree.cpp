#include <iostream>
#include "ThreadBTree.h"

//建立基础线索二叉树
void _CreateTBTree(TBTree& T) {
	char data;
	cin.get(data);

	if (data != '#') {
		T = nullptr;
	}
	else {
		T = new ThreadBTNode;
		T->data = data;
		T->Ltag = 0;
		T->Rtag = 0;
		_CreateTBTree(T->Lchild);
		_CreateTBTree(T->Rchild);
	}
}
void ThreadBTree::CreateTBTree() {
	TBTree tbtree = new ThreadBTNode;
	cout << "请按照先序输入满二叉树（用#代表空节点）：" << endl;

	_CreateTBTree(tbtree);

	this->tbtree = tbtree;
}
//前序线索化二叉树
void _CreatePreThread(TBTree& T, TBTree &pre) {
	if (T != NULL) {
		//当前节点线索化
		if (T->Lchild == NULL) {					//左孩子为空
			T->Lchild = pre;
			T->Ltag = 1;
		}
		if (pre != NULL && pre->Rchild == NULL) {
			pre->Rchild = T;
			pre->Rtag = 1;
		}
		pre = T;
		_CreatePreThread(T->Lchild, pre);
		_CreatePreThread(T->Rchild, pre);
	}
}
void ThreadBTree::CreatePreThread() {
	TBTree pre = NULL;
	_CreatePreThread(this->tbtree, pre);
}
//中序线索化二叉树
void _CreateInThread(TBTree &T, TBTree &pre) {
	if (T != NULL) {
		_CreateInThread(T->Lchild, pre);

		if (T->Lchild == NULL) {					//左孩子为空，可以线索化
			T->Lchild = pre;
			T->Ltag = 1;
		}
		if (pre != NULL && pre->Rchild == NULL) {	//前驱节点不空且没有右孩子，可以线索化
			pre->Rchild = T;
			pre->Rtag = 1;
		}
		pre = T;

		_CreateInThread(T->Rchild, pre);
	}
}
void ThreadBTree::CreateInThread() {
	TBTree pre = NULL;
	_CreateInThread(this->tbtree, pre);
}
//后序线索化二叉树
void _CreatePostThread(TBTree& T, TBTree& pre) {

}
void ThreadBTree::CreatePostThread() {
	TBTree pre = NULL;
	_CreatePostThread(this->tbtree, pre);
}
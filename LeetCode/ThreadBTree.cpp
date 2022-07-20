#include <iostream>
#include "ThreadBTree.h"

//ABC#D##EF###GHI###J##

void ThreadBTree::test() {
	this->CreateTBTree();

	////先序线索化、遍历
	//this->CreatePreThread();
	//cout << "先序线索化完成！" << endl;
	//cout << "先序线索化遍历：";
	//this->Pretraversal();
	//cout << endl;

	////中序线索化、遍历
	//this->CreateInThread();
	//cout << "中序线索化完成！" << endl;
	//cout << "中序线索化遍历：";
	//this->Intraversal();
	//cout << endl;

	//后序线索化、遍历
	this->CreatePostThread();
	cout << "中序线索化完成！" << endl;
	cout << "中序线索化遍历：";
	this->Posttraversal();
	cout << endl;
}

//建立基础线索二叉树
void _CreateTBTree(TBTree& T) {
	char data;
	cin.get(data);

	if (data == '#') {
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
void _CreatePreThread(TBTree& T, TBTree& pre) {
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

		if (T->Ltag ==0)
			_CreatePreThread(T->Lchild, pre);
		if (T->Rtag == 0)
			_CreatePreThread(T->Rchild, pre);
	}
}
void ThreadBTree::CreatePreThread() {
	TBTree pre = NULL;
	_CreatePreThread(this->tbtree, pre);

	pre->Rchild = NULL;								//空后继节点，代表线索二叉树链结束
	pre->Rtag = 1;
}
//中序线索化二叉树
void _CreateInThread(TBTree& T, TBTree& pre) {
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

	pre->Rchild = NULL;								//空后继节点，代表线索二叉树链结束
	pre->Rtag = 1;
}
//后序线索化二叉树
void _CreatePostThread(TBTree& T, TBTree& pre) {
	if (T != NULL) {
		_CreatePostThread(T->Lchild, pre);
		_CreatePostThread(T->Rchild, pre);

		if (T->Lchild == NULL) {
			T->Lchild = pre;
			T->Ltag = 1;
		}
		if (pre != NULL && pre->Rchild == NULL) {
			pre->Rchild = T;
			pre->Rtag = 1;
		}
		pre = T;
	}
}
void ThreadBTree::CreatePostThread() {
	TBTree pre = NULL;
	_CreatePostThread(this->tbtree, pre);

	pre->Rchild = NULL;								//空后继节点，代表线索二叉树链结束
	pre->Rtag = 1;
}

//遍历线索二叉树
//先序
ThreadBTNode* PreNextNode(ThreadBTNode* T) {
	if (T->Lchild != NULL && T->Ltag == 0) {
		return T->Lchild;
	}
	else {
		if (T->Rchild != NULL) {
			return T->Rchild;
		}
		else {
			return NULL;
		}
	}
}
void ThreadBTree::Pretraversal() const {
	for (ThreadBTNode* t = this->tbtree; t != NULL; t = PreNextNode(t)) {
		cout << t->data << " ";
	}
}
//中序
ThreadBTNode* InFirstNode(ThreadBTNode* T) {			//当前节点中序下的第一个节点
	while (T->Ltag == 0)							//向左孩子走到头
		T = T->Lchild;
	return T;
}
ThreadBTNode* InNextNode(ThreadBTNode* T) {			//当前节点中序下的下一个节点
	if (T->Rtag == 0) {								//存在右孩子，寻找右孩子中序下的第一个节点
		return InFirstNode(T->Rchild);
	}
	else {											//不存在右孩子，直接返回后继
		return T->Rchild;
	}
}
void ThreadBTree::Intraversal() const {
	for (ThreadBTNode* t = InFirstNode(this->tbtree); t != NULL; t = InNextNode(t)) {
		cout << t->data << " ";
	}
}
//后序
ThreadBTNode* PostFirstNode(ThreadBTNode* T) {
	//while(T)
	//while (T->Ltag == 0)
	//	T = T->Lchild;
	//if (T->Rtag == 0)
	//	T = T->Rchild;

	return NULL;
}
ThreadBTNode* PostNextNode(ThreadBTNode* T) {
	return NULL;
}
void ThreadBTree::Posttraversal() const {
	for (ThreadBTNode* t = PostFirstNode(this->tbtree); t != NULL; t = PostNextNode(t)) {
		cout << t->data << " ";
	}
}
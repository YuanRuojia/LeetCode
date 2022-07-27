#include <iostream>
#include "Btree.h"

void Btree::test() {
	this->CreateBTree();

	cout << "递归：" << endl;
	this->RecrusionNLR();   cout << endl;
	this->RecrusionLNR();	cout << endl;
	this->RecrusionLRN();	cout << endl;

	cout << "非递归：" << endl;
	this->nonRecrusionNLR();	cout << endl;
	this->nonRecrusionLNR();	cout << endl;
	this->nonRecrusionLRN();	cout << endl;

	cout << "层序：" << endl;
	this->LevelOrder();		cout << endl;
}

//创建二叉树，#表示空节点，按照前序输入满树
void _CreateBTree(BiTree& T) {
	char data;
	cin.get(data);

	if (data == '#') {											//创建空节点
		T = nullptr;	
	}
	else {														//创建非空节点
		T = new BiTNode;
		T->data = data;
		_CreateBTree(T->Lchild);
		_CreateBTree(T->Rchild);
	}
}
void Btree::CreateBTree() {
	cout << "请按照先序输入满二叉树（用#代表空节点）：" << endl;
	BiTree tree = new BiTNode;

	_CreateBTree(tree);

	this->tree = tree;
}

//递归遍历
//先序
void _RecrusionNLR(BiTree T) {
	if (T != NULL) {
		cout << T->data << " ";
		_RecrusionNLR(T->Lchild);
		_RecrusionNLR(T->Rchild);
	}
}
void Btree::RecrusionNLR() const {
	_RecrusionNLR(this->tree);
}

//中序
void _RecrusionLNR(BiTree T) {
	if (T != NULL) {
		_RecrusionLNR(T->Lchild);
		cout << T->data << " ";
		_RecrusionLNR(T->Rchild);
	}
}
void Btree::RecrusionLNR()  const {
	_RecrusionLNR(this->tree);
}
//后序
void _RecrusionLRN(BiTree T) {
	if (T != NULL) {
		_RecrusionLRN(T->Lchild);
		_RecrusionLRN(T->Rchild);
		cout << T->data << " ";
	}
}
void Btree::RecrusionLRN()  const {
	_RecrusionLRN(this->tree);
}

//非递归遍历
//先序
void _nonRecrusionNLR(BiTree T) {
	stack<BiTNode*> order;
	BiTNode* cur;
	cur = T;

	while (cur || !order.empty()) {
		if (cur) {												// 一路向左
			cout << cur->data << " ";							//访问当前节点
			order.push(cur);									//当前节点入栈
			cur = cur->Lchild;									//向左孩子走
		}
		else {													// 左孩子走到头
			cur = order.top();									//栈顶元素出栈
			order.pop();
			cur = cur->Rchild;									//向右孩子走
		}
	}
}
void Btree::nonRecrusionNLR()  const {
	_nonRecrusionNLR(this->tree);
}

//中序
void _nonRecrusionLNR(BiTree T) {
	stack<BiTNode*> order;
	BiTNode* cur;
	cur = T;

	while (cur || !order.empty()) {
		if (cur) {												// 一路向左
			order.push(cur);									//当前节点入栈
			cur = cur->Lchild;									//向左孩子走
		}
		else {													// 左孩子全部入队
			cur = order.top();									//栈顶元素出栈
			order.pop();
			cout << cur->data << " ";							//访问当前节点
			cur = cur->Rchild;									//向右孩子走
		}
	}
}
void Btree::nonRecrusionLNR()  const {
	_nonRecrusionLNR(this->tree);
}

//后序
void _nonRecrusionLRN(BiTree T) {
	stack<BiTNode*> order;
	BiTNode* cur;
	BiTNode* Accessed;
	cur = T;
	Accessed = NULL;

	while (cur || !order.empty()) {
		if (cur) {
			order.push(cur);									//当前节点入栈
			cur = cur->Lchild;									//向左孩子走
		}
		else {													// 左孩子走到头
			cur = order.top();									// 得到栈顶元素
			if (cur->Rchild && cur->Rchild != Accessed) {		//若存在右孩子且未访问
				cur = cur->Rchild;								//向右孩子走
			}
			else {												// 没有右孩子或右孩子已访问
				order.pop();									//弹出栈顶元素
				cout << cur->data << " ";						//访问当前节点
				Accessed = cur;									//标记为已访问
				cur = NULL;										//cur指针置空，重新获得栈顶元素
			}
		}
	}
}
void Btree::nonRecrusionLRN()  const {
	_nonRecrusionLRN(this->tree);
}

//层序遍历
void _LevelOrder(BiTree T) {
	queue<BiTNode*> Tqueue;
	Tqueue.push(T);											//根节点入队
	BiTNode* cur;

	while (!Tqueue.empty()) {
		cur = Tqueue.front();									//队首元素出队
		Tqueue.pop();

		cout << cur->data << " ";								//访问当前节点

		if (cur->Lchild)										//若存在左孩子，入队
			Tqueue.push(cur->Lchild);
		if (cur->Rchild)										//若存在右孩子，入队
			Tqueue.push(cur->Rchild);

	}
}
void Btree::LevelOrder()  const {
	_LevelOrder(this->tree);
}
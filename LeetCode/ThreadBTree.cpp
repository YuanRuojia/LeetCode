#include <iostream>
#include "ThreadBTree.h"

//������������������
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
	cout << "�밴����������������������#����սڵ㣩��" << endl;

	_CreateTBTree(tbtree);

	this->tbtree = tbtree;
}
//ǰ��������������
void _CreatePreThread(TBTree& T, TBTree &pre) {
	if (T != NULL) {
		//��ǰ�ڵ�������
		if (T->Lchild == NULL) {					//����Ϊ��
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
//����������������
void _CreateInThread(TBTree &T, TBTree &pre) {
	if (T != NULL) {
		_CreateInThread(T->Lchild, pre);

		if (T->Lchild == NULL) {					//����Ϊ�գ�����������
			T->Lchild = pre;
			T->Ltag = 1;
		}
		if (pre != NULL && pre->Rchild == NULL) {	//ǰ���ڵ㲻����û���Һ��ӣ�����������
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
//����������������
void _CreatePostThread(TBTree& T, TBTree& pre) {

}
void ThreadBTree::CreatePostThread() {
	TBTree pre = NULL;
	_CreatePostThread(this->tbtree, pre);
}
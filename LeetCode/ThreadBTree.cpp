#include <iostream>
#include "ThreadBTree.h"

//ABC#D##EF###GHI###J##

void ThreadBTree::test() {
	this->CreateTBTree();

	////����������������
	//this->CreatePreThread();
	//cout << "������������ɣ�" << endl;
	//cout << "����������������";
	//this->Pretraversal();
	//cout << endl;

	////����������������
	//this->CreateInThread();
	//cout << "������������ɣ�" << endl;
	//cout << "����������������";
	//this->Intraversal();
	//cout << endl;

	//����������������
	this->CreatePostThread();
	cout << "������������ɣ�" << endl;
	cout << "����������������";
	this->Posttraversal();
	cout << endl;
}

//������������������
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
	cout << "�밴����������������������#����սڵ㣩��" << endl;

	_CreateTBTree(tbtree);

	this->tbtree = tbtree;
}
//ǰ��������������
void _CreatePreThread(TBTree& T, TBTree& pre) {
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

		if (T->Ltag ==0)
			_CreatePreThread(T->Lchild, pre);
		if (T->Rtag == 0)
			_CreatePreThread(T->Rchild, pre);
	}
}
void ThreadBTree::CreatePreThread() {
	TBTree pre = NULL;
	_CreatePreThread(this->tbtree, pre);

	pre->Rchild = NULL;								//�պ�̽ڵ㣬��������������������
	pre->Rtag = 1;
}
//����������������
void _CreateInThread(TBTree& T, TBTree& pre) {
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

	pre->Rchild = NULL;								//�պ�̽ڵ㣬��������������������
	pre->Rtag = 1;
}
//����������������
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

	pre->Rchild = NULL;								//�պ�̽ڵ㣬��������������������
	pre->Rtag = 1;
}

//��������������
//����
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
//����
ThreadBTNode* InFirstNode(ThreadBTNode* T) {			//��ǰ�ڵ������µĵ�һ���ڵ�
	while (T->Ltag == 0)							//�������ߵ�ͷ
		T = T->Lchild;
	return T;
}
ThreadBTNode* InNextNode(ThreadBTNode* T) {			//��ǰ�ڵ������µ���һ���ڵ�
	if (T->Rtag == 0) {								//�����Һ��ӣ�Ѱ���Һ��������µĵ�һ���ڵ�
		return InFirstNode(T->Rchild);
	}
	else {											//�������Һ��ӣ�ֱ�ӷ��غ��
		return T->Rchild;
	}
}
void ThreadBTree::Intraversal() const {
	for (ThreadBTNode* t = InFirstNode(this->tbtree); t != NULL; t = InNextNode(t)) {
		cout << t->data << " ";
	}
}
//����
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
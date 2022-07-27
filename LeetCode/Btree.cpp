#include <iostream>
#include "Btree.h"

void Btree::test() {
	this->CreateBTree();

	cout << "�ݹ飺" << endl;
	this->RecrusionNLR();   cout << endl;
	this->RecrusionLNR();	cout << endl;
	this->RecrusionLRN();	cout << endl;

	cout << "�ǵݹ飺" << endl;
	this->nonRecrusionNLR();	cout << endl;
	this->nonRecrusionLNR();	cout << endl;
	this->nonRecrusionLRN();	cout << endl;

	cout << "����" << endl;
	this->LevelOrder();		cout << endl;
}

//������������#��ʾ�սڵ㣬����ǰ����������
void _CreateBTree(BiTree& T) {
	char data;
	cin.get(data);

	if (data == '#') {											//�����սڵ�
		T = nullptr;	
	}
	else {														//�����ǿսڵ�
		T = new BiTNode;
		T->data = data;
		_CreateBTree(T->Lchild);
		_CreateBTree(T->Rchild);
	}
}
void Btree::CreateBTree() {
	cout << "�밴����������������������#����սڵ㣩��" << endl;
	BiTree tree = new BiTNode;

	_CreateBTree(tree);

	this->tree = tree;
}

//�ݹ����
//����
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

//����
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
//����
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

//�ǵݹ����
//����
void _nonRecrusionNLR(BiTree T) {
	stack<BiTNode*> order;
	BiTNode* cur;
	cur = T;

	while (cur || !order.empty()) {
		if (cur) {												// һ·����
			cout << cur->data << " ";							//���ʵ�ǰ�ڵ�
			order.push(cur);									//��ǰ�ڵ���ջ
			cur = cur->Lchild;									//��������
		}
		else {													// �����ߵ�ͷ
			cur = order.top();									//ջ��Ԫ�س�ջ
			order.pop();
			cur = cur->Rchild;									//���Һ�����
		}
	}
}
void Btree::nonRecrusionNLR()  const {
	_nonRecrusionNLR(this->tree);
}

//����
void _nonRecrusionLNR(BiTree T) {
	stack<BiTNode*> order;
	BiTNode* cur;
	cur = T;

	while (cur || !order.empty()) {
		if (cur) {												// һ·����
			order.push(cur);									//��ǰ�ڵ���ջ
			cur = cur->Lchild;									//��������
		}
		else {													// ����ȫ�����
			cur = order.top();									//ջ��Ԫ�س�ջ
			order.pop();
			cout << cur->data << " ";							//���ʵ�ǰ�ڵ�
			cur = cur->Rchild;									//���Һ�����
		}
	}
}
void Btree::nonRecrusionLNR()  const {
	_nonRecrusionLNR(this->tree);
}

//����
void _nonRecrusionLRN(BiTree T) {
	stack<BiTNode*> order;
	BiTNode* cur;
	BiTNode* Accessed;
	cur = T;
	Accessed = NULL;

	while (cur || !order.empty()) {
		if (cur) {
			order.push(cur);									//��ǰ�ڵ���ջ
			cur = cur->Lchild;									//��������
		}
		else {													// �����ߵ�ͷ
			cur = order.top();									// �õ�ջ��Ԫ��
			if (cur->Rchild && cur->Rchild != Accessed) {		//�������Һ�����δ����
				cur = cur->Rchild;								//���Һ�����
			}
			else {												// û���Һ��ӻ��Һ����ѷ���
				order.pop();									//����ջ��Ԫ��
				cout << cur->data << " ";						//���ʵ�ǰ�ڵ�
				Accessed = cur;									//���Ϊ�ѷ���
				cur = NULL;										//curָ���ÿգ����»��ջ��Ԫ��
			}
		}
	}
}
void Btree::nonRecrusionLRN()  const {
	_nonRecrusionLRN(this->tree);
}

//�������
void _LevelOrder(BiTree T) {
	queue<BiTNode*> Tqueue;
	Tqueue.push(T);											//���ڵ����
	BiTNode* cur;

	while (!Tqueue.empty()) {
		cur = Tqueue.front();									//����Ԫ�س���
		Tqueue.pop();

		cout << cur->data << " ";								//���ʵ�ǰ�ڵ�

		if (cur->Lchild)										//���������ӣ����
			Tqueue.push(cur->Lchild);
		if (cur->Rchild)										//�������Һ��ӣ����
			Tqueue.push(cur->Rchild);

	}
}
void Btree::LevelOrder()  const {
	_LevelOrder(this->tree);
}
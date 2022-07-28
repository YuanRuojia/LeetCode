#pragma once

#include <memory>

using namespace std;

template <typename T>
struct smartListNode {
public:
	T data;
	shared_ptr<smartListNode<T>> next;
	smartListNode() : data(), next(nullptr) {}
	smartListNode(T t) : data(t), next(nullptr) {}
};

template <typename T>
class smartList
{
public:
	smartList() {
		len = 0;
		head = shared_ptr<smartListNode<T>>(new smartListNode<T>());
	}

	~smartList() {
		shared_ptr<smartListNode<T>> cur;
		while (head) {
			cur = head;
			head = cur->next;
			cur.reset();
		}
	}

	void backcreate() {
		cout << "������ڵ㣬ʹ�ÿո����: (�������������Ctrl+Z)" << endl;
		T in;
		shared_ptr<smartListNode<T>> p = head;
		while (cin >> in) {
			shared_ptr<smartListNode<T>> temp = make_shared<smartListNode<T>>(in);
			p->next = temp;
			p = temp;
			len++;
		}

		cin.clear(); // ��ռ��̻��������EOF
	} // β�巨��������

	void insert(int) {

	} // ��loc�����һ���ڵ�

	void append() {

	} // ��β����ӽڵ�

	void erase(T) {

	} // ɾ����һ��ֵΪt�Ľڵ�

	void show() {
		shared_ptr<smartListNode<T>> p = head->next;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	} // �������

private:
	int len;
	shared_ptr<smartListNode<T>> head;
};
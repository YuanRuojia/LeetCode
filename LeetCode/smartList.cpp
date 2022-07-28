#include <iostream>
#include "smartList.h"

template <typename T>
smartList<T>::smartList() {
	len = 0;
	head = shared_ptr<smartListNode<T>>(new smartListNode<T>());
}

template <typename T>
smartList<T>::~smartList() {
	shared_ptr<smartListNode<T>> cur;
	while (head->next != nullptr) {
		cur = head->next;
		head = cur->next;
		cur.reset();
	}
}

template <typename T>
void smartList<T>::backcreate() {
	cout << "请输入节点，使用空格隔开: (输入结束请输入Ctrl+Z)" << endl;
	T in;
	shared_ptr<smartListNode<T>> p = head;
	while (cin >> in) {
		smartListNode temp(in);
		p->next = temp;
		p = temp;
	}
}

template <typename T>
void smartList<T>::insert(int loc) {

}

template <typename T>
void smartList<T>::append() {

}

template <typename T>
void smartList<T>::erase(T tar) {

}

template <typename T>
void smartList<T>::show() {
	shared_ptr<smartListNode<T>> p = head->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
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
		cout << "请输入节点，使用空格隔开: (输入结束请输入Ctrl+Z)" << endl;
		T in;
		shared_ptr<smartListNode<T>> p = head;
		while (cin >> in) {
			shared_ptr<smartListNode<T>> temp = make_shared<smartListNode<T>>(in);
			p->next = temp;
			p = temp;
			len++;
		}

		cin.clear(); // 清空键盘缓冲区里的EOF
	} // 尾插法创建链表

	void insert(int) {

	} // 在loc后插入一个节点

	void append() {

	} // 在尾部添加节点

	void erase(T) {

	} // 删除第一个值为t的节点

	void show() {
		shared_ptr<smartListNode<T>> p = head->next;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	} // 输出链表

private:
	int len;
	shared_ptr<smartListNode<T>> head;
};
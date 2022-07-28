#pragma once

#include <memory>

using namespace std;

template <typename T>
struct smartListNode {
public:
	T data;
	shared_ptr<smartListNode<T>> next;
	smartListNode() : data(0), next(nullptr) {}
	smartListNode(T t) : data(t), next(nullptr) {}
};

template <typename T>
class smartList
{
public:
	smartList();
	~smartList();
	void backcreate(); // 尾插法创建链表
	void insert(int); // 在loc后插入一个节点
	void append(); // 在尾部添加节点
	void erase(T); // 删除第一个值为t的节点
	void show(); // 输出链表
private:
	int len;
	shared_ptr<smartListNode<T>> head;
};
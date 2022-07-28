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
	void backcreate(); // β�巨��������
	void insert(int); // ��loc�����һ���ڵ�
	void append(); // ��β����ӽڵ�
	void erase(T); // ɾ����һ��ֵΪt�Ľڵ�
	void show(); // �������
private:
	int len;
	shared_ptr<smartListNode<T>> head;
};
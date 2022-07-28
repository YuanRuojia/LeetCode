#pragma once

#include <memory>

template <typename T>
struct smartListNode {
	smartListNode(const T& x = T())
		: data(x)
	{}
	weak_ptr<smartListNode> next;
	weak_ptr<smartListNode> prev;
	T data;
};

template <typename T>
class smartList
{
public:
	static void Backcreate(shared_ptr<smartListNode<T>> sptr) {
		cout << "请输入节点，使用空格隔开:" << endl;
		string input;
		getline(cin, input);
		vector<string> nodes = Split(input, ' ');

		for (int i = 0; i < nodes.size(); i++) {
			shared_ptr<smartListNode<T>> temp(new T);

		}
	}
	static void Output(shared_ptr < smartListNode<T> sptr) {

	}
};
#pragma once
#ifndef MYLIST_H_
#define MYLIST_H_

#include <string>
#include <vector>

using namespace std;

typedef struct ListNode {
	string data;
	struct ListNode* next;
}ListNode, * List;

class MyList
{
private:
	List L;
public:
	void HeadCreate(); // 头插法
	void BackCreate(); // 尾插法
	void BackCreate(vector<string> datas); // 尾插法
	void Output(); // 输出
	List GetList(); // 获得链表

	void ReverseList(); // 反转链表
	void reverseBetween(int start, int end); // 反转指定区间
	void reverseKGroup(int k); // 每k组反转

	static vector<string> Split(string input, const char delim); // 字符串分割	
	static MyList* ListMerge(MyList* A, MyList* B); // 两个链表合并
	static MyList* KListMerge(vector<MyList*> Lists); // 可以用归并和分治优化
};

#endif // !MYLIST_H_
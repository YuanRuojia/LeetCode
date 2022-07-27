#pragma once
#ifndef MYLIST_H_
#define MYLIST_H_

#include <string>
#include <algorithm>
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
	void HeadCreate(); // ͷ�巨
	void BackCreate(); // β�巨
	void BackCreate(vector<string> datas); // β�巨
	void Output(); // ���
	List GetList(); // �������

	void ReverseList(); // ��ת����
	void reverseBetween(int start, int end); // ��תָ������
	void reverseKGroup(int k); // ÿk�鷴ת
	List FindKthToTail(int k); // �������k���ڵ�
	void removeNthFromEnd(int n); // ɾ��������n���ڵ�
	void sortInList(); // ��������
	void deleteDuplicates(); // ɾ���б��ظ�Ԫ��

	static vector<string> Split(string input, const char delim); // �ַ����ָ�	
	static MyList* ListMerge(MyList* A, MyList* B); // ��������ϲ�
	static MyList* KListMerge(vector<MyList*> Lists); // �����ù鲢�ͷ����Ż�
	static MyList* addInList(MyList* A, MyList* B); // �������
};

#endif // !MYLIST_H_
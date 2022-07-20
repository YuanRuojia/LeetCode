#pragma once
#ifndef MYLIST_H_
#define MYLIST_H_

#include <string>
#include "Split.h"

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
	void HeadCreate();
	void BackCreate();

	void ReverseList();
};

#endif // !MYLIST_H_
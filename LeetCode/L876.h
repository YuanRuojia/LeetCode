#pragma once
#include <iostream>
#include "MyList.h"

using namespace std;

class L876
{
private:
	MyList list;
public:
	L876();
	ListNode* middleNode(ListNode* head);
	static void TEST();
};
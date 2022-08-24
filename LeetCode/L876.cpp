#include "L876.h"

L876::L876()
{
	MyList* list = new MyList();
	list->BackCreate();
	this->list = *list;
}

ListNode* L876::middleNode(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast->next) {
		if (fast->next)
			fast = fast->next;
		if (fast->next)
			fast = fast->next;
		if (slow->next)
			slow = slow->next;
	}

	return slow;
}

void L876::TEST()
{
	L876* test = new L876();
	ListNode* middle = test->middleNode(test->list.GetList()->next);
	while (middle) {
		cout << middle->data << " ";
		middle = middle->next;
	}
	cout << endl;
}

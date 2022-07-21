#include <iostream>
#include "MyList.h"

MyList::MyList()
{
}

MyList::~MyList()
{
}

void MyList::HeadCreate() {
	cout << "请输入节点，使用空格隔开:" << endl;
	string input;
	getline(cin, input);
	vector<string> nodes = ListFunction::Split(input, ' ');

	List L = new ListNode;
	L->next = NULL;
	for (int i = 0; i < nodes.size(); i++) {
		ListNode* p = new ListNode;
		p->data = nodes[i];
		p->next = L->next;
		L->next = p;
	}

	this->L = L;
}

void MyList::BackCreate() {
	cout << "请输入节点，使用空格隔开:" << endl;
	string input;
	getline(cin, input);
	vector<string> nodes = ListFunction::Split(input, ' ');

	List L = new ListNode;
	ListNode* pre = L;
	for (int i = 0; i < nodes.size(); i++) {
		ListNode* p = new ListNode;
		p->data = nodes[i];
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;

	this->L = L;
}

void MyList::BackCreate(vector<string> datas) {
	List L = new ListNode;
	ListNode* pre = L;
	for (int i = 0; i < datas.size(); i++) {
		ListNode* p = new ListNode;
		p->data = datas[i];
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;

	this->L = L;
}

void MyList::Output() {
	ListNode* p = this->L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

List MyList::GetList() {
	return this->L;
}

void MyList::ReverseList() {
	ListNode* pre = nullptr;
	ListNode* cur = this->L->next;
	ListNode* next = nullptr;

	while (cur != NULL) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}

	this->L->next = pre;
}

//this is a list between reverse test
void MyList::reverseBetween(int start, int end) {
	int len;
	len = end - start;
	if (len < 0) {
		cout << "区间错误！" << endl;
		return;
	}

	ListNode* head = this->L->next;
	start -= 2;
	while (start > 0) {
		if (head->next) {
			head = head->next;
			start--;
		}
		else {
			cout << "区间错误！" << endl;
			return;
		}
	}
	ListNode* tail = head->next;

	ListNode* pre = head->next;
	ListNode* cur = head->next->next;
	ListNode* next = nullptr;

	while (cur != NULL && len > 0) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		len--;
	}

	head->next = pre;
	tail->next = cur;
}

void MyList::reverseKGroup(int k) {
	ListNode* head = this->L;
	ListNode* tail = this->L->next;
	ListNode* nexthead = this->L->next;

	while (nexthead != NULL) {
		for (int i = 0; i < k; i++) {
			if (nexthead != NULL) {
				nexthead = nexthead->next;
			}
			else {
				return;
			}
		}

		ListNode* pre = head->next;
		ListNode* cur = head->next->next;
		ListNode* next = nullptr;

		for (int i = 2; cur != NULL && i <= k; i++) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		
		head->next = pre;
		tail->next = cur;

		for (int i = 0; i < k; i++) {
			head = head->next;
		}
		tail = head->next;
	}
}
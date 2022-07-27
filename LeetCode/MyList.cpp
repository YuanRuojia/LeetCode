#include <iostream>
#include "MyList.h"

void MyList::HeadCreate() {
	cout << "请输入节点，使用空格隔开:" << endl;
	string input;
	getline(cin, input);
	vector<string> nodes = Split(input, ' ');

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
	vector<string> nodes = Split(input, ' ');

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

List MyList::FindKthToTail(int k) {
	ListNode* p = this->GetList()->next;
	ListNode* tail = p;

	while (k > 1 && tail) {
		tail = tail->next;
		k--;
	}

	if (!tail) return NULL;		

	while (tail->next) {
		p = p->next;
		tail = tail->next;
	}

	return p;
}

void MyList::removeNthFromEnd(int n)
{
	if (n < 1) {
		cout << "n非法！" << endl;
		return;
	}
	ListNode* tar = MyList::FindKthToTail(n+1);
	if (!tar) {
		cout << "n非法！" << endl;
		return;
	}

	ListNode* temp = tar->next;
	tar->next = temp->next;
	delete temp;
}

bool cmp(string a, string b) {
	int ia = atoi(a.c_str());
	int ib = atoi(b.c_str());
	return ia < ib;
}

void MyList::sortInList()
{
	vector<string> datas;
	ListNode* p = this->L->next;

	while (p) {
		datas.push_back(p->data);
		p = p->next;
	}

	sort(datas.begin(), datas.end(), cmp);

	this->L = nullptr;
	this->BackCreate(datas);
}

void MyList::deleteDuplicates()
{
	ListNode* p = this->L->next;
	if (!p) return;
	if (!p->next) return;

	while (p->next) {
		if (p->data == p->next->data) {
			ListNode* temp = p->next;
			p->next = p->next->next;

			delete temp;
			temp = NULL;
		}
		else {
			p = p->next;
		}
	}
}

vector<string> MyList::Split(string input, const char delim) {
	int len = input.length();
	vector<string> ans;
	for (int i = 0; i < len; ) {
		int spacei = input.find(delim, i);

		//找到最后一个单词
		if (spacei == -1) {
			spacei = len;
		}

		string temp = input.substr(i, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(spacei) - i);
		ans.push_back(temp);
		i = spacei + 1;
	}

	return ans;
}

MyList* MyList::ListMerge(MyList* A, MyList* B) {
	ListNode* Pa = A->GetList()->next;
	ListNode* Pb = B->GetList()->next;

	MyList* merged = new MyList;
	vector<string> datas;

	while (Pa != NULL && Pb != NULL) {
		if (atoi(Pa->data.c_str()) < atoi(Pb->data.c_str())) {
			datas.push_back(Pa->data);
			Pa = Pa->next;
		}
		else {
			datas.push_back(Pb->data);
			Pb = Pb->next;
		}
	}

	if (Pa) {
		while (Pa != NULL) {
			datas.push_back(Pa->data);
			Pa = Pa->next;
		}
	}
	if (Pb) {
		while (Pb != NULL) {
			datas.push_back(Pb->data);
			Pb = Pb->next;
		}
	}

	merged->BackCreate(datas);
	delete A;
	delete B;

	return merged;
}

// 可以用归并和分治优化
MyList* MyList::KListMerge(vector<MyList*> Lists) {
	int lsize = Lists.size();
	if(lsize == 0) return NULL;

	while (lsize > 1) {
		Lists.push_back(MyList::ListMerge(Lists[0], Lists[1]));
		Lists.erase(Lists.begin(), Lists.begin() + 2);
		lsize--;
	}

	return Lists[0];
}

MyList* MyList::addInList(MyList* A, MyList* B)
{
	MyList* SUM = new MyList;

	A->ReverseList();
	B->ReverseList();
	ListNode* pA = A->L->next;
	ListNode* pB = B->L->next;

	int carry = 0;
	vector<string> sum;
	while (pA && pB) {
		int temp = atoi(pA->data.c_str()) + atoi(pB->data.c_str()) + carry;
		carry = 0;
		if (temp > 9) {
			carry = 1;
			temp %= 10;
		}
		sum.push_back(to_string(temp));

		pA = pA->next;
		pB = pB->next;
	}

	if (pA) {
		while (pA) {
			int temp = atoi(pA->data.c_str()) + carry;
			carry = 0;
			if (temp > 9) {
				carry = 1;
				temp %= 10;
			}
			sum.push_back(to_string(temp));
			pA = pA->next;
		}
	}
	if (pB) {
		while (pB) {
			int temp = atoi(pB->data.c_str()) + carry;
			carry = 0;
			if (temp > 9) {
				carry = 1;
				temp %= 10;
			}
			sum.push_back(to_string(temp));
			pB = pB->next;
		}
	}

	if (carry == 1)
		sum.push_back("1");

	SUM->BackCreate(sum);
	SUM->ReverseList();

	delete A;
	A = nullptr;
	delete B;
	B = nullptr;

	return SUM;
}

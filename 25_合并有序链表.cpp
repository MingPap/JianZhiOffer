#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* m_next;
	ListNode(int x) :val(x), m_next(nullptr) {
	};
};

ListNode* ReverseList(ListNode* head)
{
	ListNode*prev = nullptr;
	ListNode*pnode = head;
	ListNode*ReverseHead = nullptr;

	while (pnode!=nullptr)
	{
		ListNode* pnext = pnode->m_next;
		if (pnext == nullptr)
			ReverseHead = pnode;

		pnode->m_next = prev;
		prev = pnode;
		pnode = pnext;

	}

	return ReverseHead;
} 

int main()
{
	ListNode head(0);
	ListNode node1(1);
	ListNode node2(2);

	head.m_next = &node1;
	node1.m_next = &node2;

	ListNode* t = ReverseList(&head);

	while (t!=nullptr)
	{
		printf("%d", t->val);
		printf("\n");
		t = t->m_next;
	}

	system("pause");
}
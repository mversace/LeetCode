#pragma once
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
#include <stack>
using std::stack;
class Solution143 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	static void reorderList(ListNode* head) {
		// 先把需要调整位置的node存入stack
		if (!head) return;
		ListNode* pOne = head;
		ListNode* pTwo = head;
		while (pOne && pTwo && pTwo->next)
		{
			pOne = pOne->next;
			pTwo = pTwo->next->next;
		}

		// pOne后边的都是需要调整的node
		stack<ListNode*> s;
		pTwo = pOne;
		while (pOne->next)
		{
			s.push(pOne->next);
			pOne = pOne->next;
		}
		pTwo->next = nullptr;

		// 从头开始遍历
		pOne = head;
		while (pOne && !s.empty())
		{
			ListNode* p = s.top();
			s.pop();
			pTwo = pOne->next;
			pOne->next = p;
			p->next = pTwo;
			pOne = pTwo;
		}
	}

	static void test()
	{
		ListNode a(1);
		ListNode b(2);
		ListNode c(3);
		ListNode d(4);
		ListNode e(5);
		a.next = &b;
		b.next = &c;
		c.next = &d;
		//d.next = &e;
		reorderList(&a);
		int n = 0;
	}
};
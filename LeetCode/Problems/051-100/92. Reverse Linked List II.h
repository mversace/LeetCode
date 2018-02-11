#pragma once
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

class Solution92 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	static ListNode* reverseBetween(ListNode* head, int m, int n) {
		// A->B->C->D 2 4
		// pm = A,p = B
		// A->C->B->D
		// A->D->C->B
		ListNode* p = head;
		ListNode *pm = nullptr;
		while (m > 1 && p)
		{
			pm = p;
			p = p->next;
			--m;
			--n;
		}
		
		while (n > 1 && p)
		{
			if (!pm)
			{
				// A->B->C->null
				// p = A
				// B->A->C->null
				// p = A
				ListNode* pNext = p->next->next; 
				p->next->next = head;
				head = p->next;
				p->next = pNext; 
			}
			else
			{
				// A->B->C->D->null
				// pm = A
				// p = B
				// A->C->B->D->null
				// pm = A, p = B
				// A->B->C->null
				// pm = A, p = B
				ListNode* pNext = p->next->next;
				p->next->next = pm->next;
				pm->next = p->next;
				p->next = pNext;
			}
			--n;
		}
		return head;
	}

	static void test()
	{
		ListNode a(1);
		ListNode b(2);
		ListNode c(3);
		ListNode d(4);
		a.next = &b;
		b.next = &c;
//		c.next = &d;
		reverseBetween(&a, 2, 3);
	}
};
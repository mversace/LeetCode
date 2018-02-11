#pragma once
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

class Solution82 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	static ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head, *pt = head;
		head = nullptr;
		while (p)
		{
			while (p && p->next && p->val == p->next->val)
			{
				p = p->next;

				if (p && (!p->next || p->val != p->next->val))
					p = p->next;
			}

			if (!p) break;

			if (!head)
			{
				head = p;
				pt = head;
			}
			else
			{
				pt->next = p;
				pt = p;
			}
			p = p->next;
			pt->next = nullptr;
		}
		return head;
	}

	static void test()
	{
		ListNode a(1);
		ListNode b(2);
		ListNode c(2);
		a.next = &b;
	//	b.next = &c;
		deleteDuplicates(&a);
	}
};
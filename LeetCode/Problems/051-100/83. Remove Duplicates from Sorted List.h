#pragma once
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head, *pt = head;
		head = nullptr;
		while (p)
		{
			while (p && p->next && p->val == p->next->val)
			{
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
};
#pragma once
/*
Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
*/

// Definition for singly-linked list.

class Solution61 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	static ListNode* rotateRight(ListNode* head, int k) {
		// if k > the list's len. then repeat again.fuck it!
		ListNode *p1 = head, *p2 = head;
		int nLen = 0;
		while (p2 && k)
		{
			p2 = p2->next;
			--k;
			++nLen;
		}

		if (k && nLen)
		{
			k %= nLen;
			p2 = head;
			while (p2 && k)
			{
				p2 = p2->next;
				--k;
			}
		}

		while (p2 && p2->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		if (p1 && p1->next && p2)
		{
			p2->next = head;
			head = p1->next;
			p1->next = nullptr;
		}
		return head;
	}

	static void test()
	{
		ListNode a1(1), a2(2), a3(3), a4(4), a5(5);
		a1.next = &a2;
// 		a2.next = &a3;
// 		a3.next = &a4;
// 		a4.next = &a5;
		rotateRight(nullptr, 1);
	}
};
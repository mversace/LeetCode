#pragma once
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

class Solution24 {
private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
public:
	static ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* pHead = head->next;
		head->next = pHead->next;
		pHead->next = head;
	
		ListNode* pNode = pHead->next;
		while (pNode->next && pNode->next->next)
		{
			ListNode* pTemp = pNode->next;
			pNode->next = pNode->next->next;
			pTemp->next = pNode->next->next;
			pNode->next->next = pTemp;

			pNode = pNode->next->next;
		}
		
		return pHead;
	}

	static void test()
	{
		ListNode a(1);
		ListNode b(2);
		ListNode c(3);
		ListNode d(4);
		a.next = &b;
		b.next = &c;
		c.next = &d;
		
		swapPairs(&a);
	}
};
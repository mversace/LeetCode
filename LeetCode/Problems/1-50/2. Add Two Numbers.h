#pragma once
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution2 {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pHead = new ListNode(0);
		ListNode* pNode = pHead;

		while (l1 || l2)
		{
			if (l1)
			{
				pNode->val += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				pNode->val += l2->val;
				l2 = l2->next;
			}

			if (l1 || l2 || pNode->val >= 10)
			{
				pNode->next = new ListNode(pNode->val / 10);
				pNode->val %= 10;
				pNode = pNode->next;
			}
		}
		return pHead;
	}

	static void Test()
	{
		ListNode* pHead1 = new ListNode(2);
		pHead1->next = new ListNode(4);
		pHead1->next->next = new ListNode(3);

		ListNode* pHead2 = new ListNode(5);
		pHead2->next = new ListNode(6);
		pHead2->next->next = new ListNode(4);

		ListNode* pRet = addTwoNumbers(pHead1, pHead2);

		while (pHead1)
		{
			auto pTemp = pHead1->next;
			delete pHead1;
			pHead1 = pTemp;
		}
		while (pHead2)
		{
			auto pTemp = pHead2->next;
			delete pHead2;
			pHead2 = pTemp;
		}
		while (pRet)
		{
			auto pTemp = pRet->next;
			delete pRet;
			pRet = pTemp;
		}
	}
};
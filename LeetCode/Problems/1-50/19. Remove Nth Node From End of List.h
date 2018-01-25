#pragma once
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass
*/

#include <map>
using std::map;

class Solution19 {
private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		map<int, ListNode*> mapTemp;
		ListNode* pData = head;
		ListNode* pReturn = head;
		int nIndex = 0;
		while (pData)
		{
			mapTemp[nIndex++] = (pData);
			pData = pData->next;
		}

		int nSize = (int)mapTemp.size();
		if (n <= nSize)
		{
			ListNode* pDel = mapTemp[nSize - n];
			ListNode* pPre = mapTemp[nSize - n - 1];
			ListNode* pNext = mapTemp[nSize - n + 1];

			if (pPre) pPre->next = pNext;
			else pReturn = pNext;

			if (pDel) delete pDel;
		}

		return pReturn;
	}
};
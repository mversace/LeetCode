#pragma once
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/


struct ListNode {
    int val;
    ListNode *next;     
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* pResult = nullptr;
		ListNode* pPtr = nullptr;
		ListNode** pTemp = nullptr;

		if (!l1 && l2) return l2;
		if (l1 && !l2) return l1;
		if (!l1 && !l2) return nullptr;

		while (l1 || l2)
		{
			if (l1 == nullptr) pTemp = &l2;
			else if (l2 == nullptr) pTemp = &l1;
			else
				pTemp = l1->val <= l2->val ? &l1 : &l2;
			
			if (!pResult)
			{
				pResult = *pTemp;
				pPtr = pResult;
			}
			else
			{
				pPtr->next = *pTemp;
				pPtr = pPtr->next;
			}
			*pTemp = (*pTemp)->next;
		}

		return pResult;
	}
};
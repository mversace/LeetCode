#pragma once
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	bool hasCycle(ListNode *head) {
		ListNode* pOne = head;
		ListNode* pTwo = head;
		while (pOne && pTwo && pTwo->next)
		{
			pOne = pOne->next;
			pTwo = pTwo->next->next;
			if (pOne == pTwo)
				return true;
		}
		return false;
	}
};
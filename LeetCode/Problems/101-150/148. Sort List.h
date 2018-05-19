#pragma once
/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	ListNode* sortList(ListNode* head) {
		// 链表排序蠢得一笔，不知道有什么意义
		if (!head) return nullptr;
		ListNode* pNewHead = head;
		vector<int> vfuck;
		while (head)
		{
			vfuck.push_back(head->val);
			head = head->next;
		}

		sort(vfuck.begin(), vfuck.end());
		head = pNewHead;
		int i = 0;
		while (head)
		{
			head->val = vfuck[i++];
			head = head->next;
		}

		return pNewHead;
	}
};
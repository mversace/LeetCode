#pragma once
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
class Solution109 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
	{
		if (head == tail)
			return nullptr;
		if (head->next == tail)
			return new TreeNode(head->val);

		ListNode* pTemp = head;
		ListNode* pMid = head;
		while (pTemp != tail && pTemp->next != tail)
		{
			pMid = pMid->next;
			pTemp = pTemp->next->next;
		}
		TreeNode* pNew = new TreeNode(pMid->val);
		pNew->left = sortedListToBST(head, pMid);
		pNew->right = sortedListToBST(pMid->next, tail);
		return pNew;
	}

	static TreeNode* sortedListToBST(ListNode* head) {
		return sortedListToBST(head, nullptr);
	}

	static void test()
	{
		ListNode a = -10;
		ListNode b = -3;
		ListNode c = 0;
		ListNode d = 5;
		ListNode e = 9;
		a.next = &b;
		b.next = &c;
		c.next = &d;
		d.next = &e;
		sortedListToBST(&a);
	}
};
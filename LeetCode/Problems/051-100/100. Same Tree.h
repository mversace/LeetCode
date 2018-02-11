#pragma once
/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:

Input:     1         1
		  / \       / \
		 2   3     2   3

[1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
		  /           \
		 2             2

[1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
		  / \       / \
		 2   1     1   2

[1,2,1],   [1,1,2]

Output: false
*/

class Solution100 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (p && q)
			return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		return false;
	}

	static void test()
	{
		TreeNode a(0);
		isSameTree(nullptr, &a);
	}
};
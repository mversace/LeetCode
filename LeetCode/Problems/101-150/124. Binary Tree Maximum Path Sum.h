#pragma once
/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

	1
   / \
  2   3
Return 6.
*/

class Solution124 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static int maxPathSum(TreeNode* pNode, int& n)
	{
		// 以pNode为根节点的path最大值
		if (!pNode) return 0;
		int l = maxPathSum(pNode->left, n);
		int r = maxPathSum(pNode->right, n);
		if (l < 0) l = 0;
		if (r < 0) r = 0;
		n = max(n, l + r + pNode->val);
		return pNode->val + max(l, r);
	}

	static int maxPathSum(TreeNode* root) {
		int n = INT_MIN;
		maxPathSum(root, n);
		return n;
	}

	static void test()
	{
		TreeNode a(1), b(2), c(3);
		a.left = &b;
		a.right = &c;
		maxPathSum(&a);
	}
};
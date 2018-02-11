#pragma once
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
2
/ \
1   3
Binary tree [2,1,3], return true.
Example 2:
1
/ \
2   3
Binary tree [1,2,3], return false.
*/
#include <stack>
using std::stack;
class Solution98 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	static bool isValidBST(TreeNode* root) {
		// 采用中序遍历：中序遍历是对于BST来说是升序遍历
		long long llMax = LLONG_MIN;
		stack<TreeNode*> s;
		while (root || !s.empty())
		{
			if (root)
			{
				s.push(root);
				root = root->left;
			}
			else
			{
				TreeNode* p = s.top();
				s.pop();

				if ((long long)p->val <= llMax) return false;
				llMax = (long long)p->val;
				
				root = p->right;
			}
		}
		return true;
	}

	static void test()
	{
		TreeNode a(2);
		TreeNode b(1);
		TreeNode c(3);
		a.left = &b;
		a.right = &c;
		isValidBST(&a);
	}
};
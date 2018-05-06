#pragma once
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example 1:

Given the following tree [3,9,20,null,null,15,7]:

     3
    / \
   9  20
 /  \
15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

      1
     / \
    2   2
   / \
  3   3
 / \
4   4
Return false.
*/
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	int depth(TreeNode* root)
	{
		if (!root) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}

	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int l = depth(root->left);
		int r = depth(root->right);
		return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};
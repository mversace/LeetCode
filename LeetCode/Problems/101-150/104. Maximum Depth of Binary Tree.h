#pragma once
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

	  3
     / \
    9  20
   / \
  15  7
return its depth = 3.
*/
#include <algorithm>
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
	}
};
#pragma once
/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};
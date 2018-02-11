#pragma once
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	 1
	/ \
   2   2
  / \ / \
 3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
  1
 / \
2   2
 \   \
 3    3
*/

class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	bool isSymmetric(TreeNode* pTree1, TreeNode* pTree2)
	{
		if (!pTree1 && !pTree2) return true;
		if (pTree1 && pTree2)
		{
			return (pTree1->val == pTree2->val && isSymmetric(pTree1->left, pTree2->right) && isSymmetric(pTree1->right, pTree2->left));
		}
		return false;
	}

	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}
};
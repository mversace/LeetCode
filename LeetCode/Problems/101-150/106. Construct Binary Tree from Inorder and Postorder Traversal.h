#pragma once
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

3
/ \
9  20
/  \
15   7
*/

#include <vector>
using std::vector;
class Solution106 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	static TreeNode* buildTree(vector<int>& inorder, int x1, int x2, vector<int>& postorder, int y1, int y2)
	{
		if (y2 < 0) return nullptr;
		TreeNode* p = new TreeNode(postorder[y2]);
		for (int i = x1; i <= x2; ++i)
		{
			if (inorder[i] == postorder[y2])
			{
				if (i > x1)
				{
					p->left = buildTree(inorder, x1, i - 1, postorder, y1, y1 + i - x1 - 1);
				}
				if (i < x2)
				{
					p->right = buildTree(inorder, i + 1, x2, postorder, y1 + i - x1, y2 - 1);
				}

				break;
			}
		}
		return p;
	}

	static TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		// 前序 根左右
		// 中序 左根右
		// 后序 左右根
		int n = (int)inorder.size();
		return buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
	}

	static void test()
	{
		buildTree(vector<int>{9, 3, 15, 20, 7}, vector<int>{9, 15, 7, 20, 3});
	}

};
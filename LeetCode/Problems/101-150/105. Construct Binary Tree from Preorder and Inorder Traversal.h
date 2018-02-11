#pragma once
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
 / \
15  7
*/
#include <vector>
using std::vector;
class Solution105 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return nullptr;

		TreeNode* p = new TreeNode(preorder[0]);
		int n = (int)inorder.size();
		for (int i = 0; i < n; ++i)
		{
			if (inorder[i] == preorder[0])
			{
				if (i > 0)
				{
					vector<int> vp(preorder.begin() + 1, preorder.begin() + i + 1);
					vector<int> vi(inorder.begin(), inorder.begin() + i);
					p->left = buildTree(vp, vi);
				}
				if (i < n - 1)
				{
					vector<int> vp(preorder.begin() + i + 1, preorder.end());
					vector<int> vi(inorder.begin() + i + 1, inorder.end());
					p->right = buildTree(vp, vi);
				}

				break;
			}
		}
		return p;
	}

	static void test()
	{
		buildTree(vector<int>{1, 2, 4, 3}, vector<int>{1, 2, 3, 4});
	}
};
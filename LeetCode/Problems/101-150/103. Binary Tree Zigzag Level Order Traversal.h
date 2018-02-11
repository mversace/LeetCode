#pragma once
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
     3
    / \
   9  20
  / \
 15  7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]
*/
#include <vector>
using std::vector;
class Solution103 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		// ≤„–Ú±È¿˙
		vector<vector<int>> v;
		vector<int> vi;
		vector<TreeNode*> vt, vtl;
		vt.push_back(root);
		bool bLeft = false;
		for (int i = 0; i < (int)vt.size(); ++i)
		{
			int n = (int)vt.size();
			if (!vt[i]) continue;
			if (vt[i]->left) vtl.push_back(vt[i]->left);
			if (vt[i]->right) vtl.push_back(vt[i]->right);
			vi.push_back(vt[i]->val);
			if (i == n - 1)
			{
				if (bLeft)
					reverse(vi.begin(), vi.end());
				v.push_back(vi);
				vi.clear();
				vt = vtl;
				vtl.clear();
				i = -1;
				bLeft = !bLeft;
			}
		}
		return v;
	}

	static void test()
	{
		TreeNode a(3);
		TreeNode b(9);
		TreeNode c(20);
		TreeNode d(15);
		TreeNode e(7);
		a.left = &b;
		a.right = &c;
		c.left = &d;
		c.right = &e;
		zigzagLevelOrder(&a);
	}
};
#pragma once
/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
	 3
    / \
   9  20
  / \
 15  7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
*/
#include <vector>
using std::vector;
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	vector<vector<int>> levelOrder(TreeNode* root) {
		// ≤„–Ú±È¿˙
		vector<vector<int>> v;
		vector<int> vi;
		vector<TreeNode*> vt, vtl;
		vt.push_back(root);

		for (int i = 0; i < (int)vt.size(); ++i)
		{
			if (!vt[i]) continue;
			if (vt[i]->left) vtl.push_back(vt[i]->left);
			if (vt[i]->right) vtl.push_back(vt[i]->right);
			vi.push_back(vt[i]->val);
			if (i == (int)vt.size() - 1)
			{
				v.push_back(vi);
				vi.clear();
				vt = vtl;
				vtl.clear();
				i = -1;
			}
		}
		return v;
	}
};
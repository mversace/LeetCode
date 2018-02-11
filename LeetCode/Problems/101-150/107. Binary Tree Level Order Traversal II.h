#pragma once
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
      3
     / \
    9  20
   / \
  15  7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		// 无意义的垃圾题目，102结果reverse即可
		// 层序遍历
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
		reverse(v.begin(), v.end());
		return v;
	}
};
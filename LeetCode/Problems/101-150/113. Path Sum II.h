#pragma once
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

			5
		   / \
		  4   8
		 /   / \
		11  13  4
	   /  \      \
	  7    2      1

return
[
	[5,4,11,2],
	[5,8,4,5]
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

	void CheckPath(vector<vector<int>>& vv, vector<int> v, TreeNode* pNode, int sum)
	{
		if (!pNode) return;
		if (!pNode->left && !pNode->right && pNode->val == sum)
		{
			v.push_back(pNode->val);
			vv.push_back(v);
			return;
		}

		v.push_back(pNode->val);
		CheckPath(vv, v, pNode->left, sum - pNode->val);
		CheckPath(vv, v, pNode->right, sum - pNode->val);
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> vv;
		vector<int> v;
		CheckPath(vv, v, root, sum);
		return vv;
	}
};
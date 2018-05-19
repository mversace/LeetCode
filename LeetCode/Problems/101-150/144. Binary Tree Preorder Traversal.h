#pragma once
/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
 1
  \
  2
 /
3

Output: [1,2,3]
*/
#include <vector>
#include <stack>
using std::vector;
using std::stack;
class Solution144 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	void TryPreOrder(vector<int>& v, TreeNode* pNode)
	{
		if (!pNode) return;
		v.push_back(pNode->val);
		TryPreOrder(v, pNode->left);
		TryPreOrder(v, pNode->right);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		// 前序遍历，根左右
		vector<int> v;
		TryPreOrder(v, root);
		return v;
	}

	vector<int> preorderTraversalEx(TreeNode* root)
	{
		// 迭代实现
		vector<int> v;
		if (!root) return v;

		stack<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* p = q.top();
			q.pop();
			v.push_back(p->val);
			if (p->right) q.push(p->right);
			if (p->left) q.push(p->left);
		}
		return v;
	}
};
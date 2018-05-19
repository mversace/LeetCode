#pragma once
/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
    1
     \
      2
     /
    3

Output: [3,2,1]
*/
#include <vector>
#include <stack>
using std::vector;
using std::stack;
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	void TryPostOrder(vector<int>& v, TreeNode* pNode)
	{
		if (!pNode) return;
		TryPostOrder(v, pNode->left);
		TryPostOrder(v, pNode->right);
		v.push_back(pNode->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		// 后序遍历，左右根
		vector<int> v;
		TryPostOrder(v, root);
		return v;
	}

	vector<int> postorderTraversalEx(TreeNode* root)
	{
		// 迭代实现
		vector<int> v;
		if (!root) return v;

		stack<TreeNode*> q;
		q.push(root);
		TreeNode* pLast = nullptr;
		while (!q.empty())
		{
			TreeNode* p = q.top();
			if ((!p->left && !p->right) || (pLast && (pLast == p->left || pLast == p->right)))
			{
				v.push_back(p->val);
				q.pop();
				pLast = p;
			}
			else
			{
				if (p->right) q.push(p->right);
				if (p->left) q.push(p->left);
			}
		}
		return v;
	}
};
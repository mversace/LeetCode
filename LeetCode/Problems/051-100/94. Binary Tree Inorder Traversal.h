#pragma once
/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
1
 \
  2
 /
3
return [1,3,2].
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
	void TryTraversal(vector<int>& v, TreeNode* p)
	{
		if (p)
		{
			TryTraversal(v, p->left);
			v.push_back(p->val);
			TryTraversal(v, p->right);
		}
	}
	vector<int> inorderTraversalEx(TreeNode* root) {
		vector<int> v;
		TryTraversal(v, root);
		return v;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;

		while (root || !s.empty())
		{
			if (root)
			{
				s.push(root);
				root = root->left;
			}
			else
			{
				TreeNode* p = s.top();
				s.pop();
				v.push_back(p->val);
				root = p->right;
			}
		}
		
		return v;
	}
};
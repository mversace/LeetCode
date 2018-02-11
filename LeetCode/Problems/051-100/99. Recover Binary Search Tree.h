#pragma once
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/
#include <vector>
#include <stack>
#include <algorithm>
using std::vector;
using std::stack;
class Solution99 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	
	static void recoverTree(TreeNode* root) {
		// 中序遍历，然后排序对比不同的地方
		vector<TreeNode*> v;
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
				v.push_back(p);
				root = p->right;
			}
		}
		vector<TreeNode*> vt = v;
		sort(vt.begin(), vt.end(), [](TreeNode* &pOne, TreeNode* &pTwo) {return pOne->val < pTwo->val; });
		int n = (int)v.size();
		TreeNode *pOne = nullptr, *pTwo = nullptr;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] != vt[i])
			{
				if (!pOne) pOne = v[i];
				else if (!pTwo) pTwo = v[i];
				else break;
			}
		}
		int m = pOne->val;
		pOne->val = pTwo->val;
		pTwo->val = m;
	}

	static void test()
	{

	}
};
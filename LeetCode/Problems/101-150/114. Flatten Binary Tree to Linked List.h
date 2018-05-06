#pragma once
/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

		1
	   / \
	  2   5
	 / \   \
	3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
	 \
	  4
	   \
		5
		 \
		  6
*/
#include <stack>
using std::stack;
class Solution114 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static void flatten(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode* pNode = root;
		while ((pNode && (pNode->left || pNode->right)) || !s.empty())
		{
			if (pNode->left || pNode->right)
			{
				if (!pNode->left)
				{
					pNode = pNode->right;
					continue;
				}
					
				if (pNode->right)
					s.push(pNode->right);
					
				pNode->right = pNode->left;
				pNode->left = nullptr;
				pNode = pNode->right;

			}
			else
			{
				TreeNode* pTemp = s.top();
				s.pop();
				pNode->right = pTemp;
				pNode = pNode->right;
			}
		}
	}

	static void test()
	{
		TreeNode a(3);
		TreeNode b(1);
		TreeNode c(4);
		TreeNode d(2);
		a.left = &b;
		a.right = &c;
		b.right = &d;
		flatten(&a);
	}
};
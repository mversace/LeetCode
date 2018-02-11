#pragma once
/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
*/
#include <vector>
using std::vector;
class Solution95 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};

	static vector<TreeNode*> TryGetTree(int nBegin, int nEnd)
	{
		vector<TreeNode*> v;
		if (nBegin > nEnd)
		{
			v.push_back(nullptr);
		}
		else if (nBegin == nEnd)
		{
			v.push_back(new TreeNode(nBegin));
		}
		else
		{
			for (int i = nBegin; i <= nEnd; ++i)
			{
				vector<TreeNode*> vl = TryGetTree(nBegin, i - 1);
				vector<TreeNode*> vr = TryGetTree(i + 1, nEnd);

				for (auto l : vl)
				{
					for (auto r : vr)
					{
						TreeNode* pt = new TreeNode(i);
						pt->left = l;
						pt->right = r;
						v.push_back(pt);
					}
				}
			}
		}
		return v;
	}

	static vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode*>{};
		return TryGetTree(1, n);
	}

	static void test()
	{
		generateTrees(0);
	}
};
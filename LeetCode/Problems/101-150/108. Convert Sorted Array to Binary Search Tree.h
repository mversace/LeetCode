#pragma once
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

          0
         / \
       -3   9
       /   /
     -10  5
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
	TreeNode* sortedArrayToBST(vector<int>& nums, int nBegin, int nEnd)
	{
		if (nEnd < nBegin) return nullptr;
		int nMid = (nBegin + nEnd) / 2;
		TreeNode* p = new TreeNode(nums[nMid]);
		p->left = sortedArrayToBST(nums, nBegin, nMid - 1);
		p->right = sortedArrayToBST(nums, nMid + 1, nEnd);
		return p;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, (int)nums.size() - 1);
	}
};
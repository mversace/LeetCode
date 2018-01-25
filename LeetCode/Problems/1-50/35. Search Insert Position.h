#pragma once
/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0
*/
#include <vector>
using std::vector;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int nLeft = 0;
		int nRight = (int)nums.size();
		if (target > nums.back()) return nRight;
		while (nLeft < nRight)
		{
			int nMid = (nLeft + nRight) / 2;
			if (nums[nMid] == target)
				return nMid;
			if (nums[nMid] > target)
				nRight = nMid;
			else
				nLeft = nMid + 1;
		}
		return nLeft;
	}
};
#pragma once
/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

*/
#include <vector>
using std::vector;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int nIdx = 0;
		while (nIdx < (int)nums.size())
		{
			if (nIdx > 0 && nums[nIdx] == nums[nIdx - 1])
				nums.erase(nums.begin() + nIdx);
			else
				++nIdx;
		}
		return (int)nums.size();
	}
};
#pragma once
/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <vector>
using std::vector;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int nSize = (int)nums.size();
		for (int i = 0; i < nSize; ++i)
		{
			while (nums[i] > 0 && nums[i] != i + 1 && nums[i] - 1 < nSize)
			{
				if (nums[i] == nums[nums[i] - 1])
				break;

				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		int i = 0;
		for (; i < nSize; ++i)
		{
			if (nums[i] != i + 1)
				break;
		}
		return (i + 1);
	}
};
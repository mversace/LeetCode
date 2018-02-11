#pragma once
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include <vector>
using std::vector;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int nLen = (int)nums.size();
		int nMax = 0;
		int nCurrentMax = 0;
		for (int i = 0; i < nLen; ++i)
		{
			nMax = max(nMax, i + nums[i]);
			if (nMax >= nLen - 1)
				return true;

			if (i == nCurrentMax)
			{
				if (nCurrentMax == nMax && i != nLen - 1)
					return false;

				nCurrentMax = nMax;
			}
		}
		return true;
	}
};
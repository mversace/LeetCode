#pragma once
/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <vector>
using std::vector;

class Solution34 {
public:
	static vector<int> searchRange(vector<int>& nums, int target) {
		int nStart = 0;
		int nEnd = (int)nums.size();
		int nLeft = 0;
		int nRight = 0;
		while (nStart < nEnd)
		{
			int nMid = (nStart + nEnd) / 2;
			if (nums[nMid] >= target)
				nEnd = nMid;
			else
				nStart = nMid + 1;
		}

		nLeft = nStart;
		nEnd = (int)nums.size();
		while (nStart < nEnd)
		{
			int nMid = (nStart + nEnd) / 2;
			if (nums[nMid] > target)
				nEnd = nMid;
			else
				nStart = nMid + 1;
		}
		nRight = nStart;

		if (nLeft == nRight)
		{
			return vector<int>{-1, -1};
		}
		return vector<int>{nLeft, nRight - 1};
	}

	static void test()
	{
		vector<int> vec = {};
		searchRange(vec, 0);
	}
};
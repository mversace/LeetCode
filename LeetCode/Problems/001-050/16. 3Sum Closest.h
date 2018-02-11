#pragma once
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <vector>
#include <algorithm>
using std::vector;

class Solution16 {
public:
	static int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int nMaxDis = INT_MAX;
		int nResult = 0;
		int nLen = (int)nums.size();
		for (int i = 0; i < nLen - 2; ++i)
		{
			int nLeft = i + 1;
			int nRight = nLen - 1;
			while (nLeft < nRight)
			{
				int nSum = nums[i] + nums[nLeft] + nums[nRight];
				int nDis = abs(nSum - target);

				if (nDis == 0) return nSum;

				if (nDis < nMaxDis)
				{
					nMaxDis = nDis;
					nResult = nSum;
				}

				if (nSum > target)
					--nRight;
				else if (nSum < target)
					++nLeft;
			}
		}
		return nResult;
	}

	static void test()
	{
		vector<int> a = {0, 1, 2};
		threeSumClosest(a, 3);
	}
};
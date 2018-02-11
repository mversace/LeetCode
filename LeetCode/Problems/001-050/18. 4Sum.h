#pragma once
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
#include <vector>
#include <algorithm>
using std::vector;

class Solution18 {
public:
	static vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> vec;

		int nLen = (int)nums.size();
		if (nLen < 4) return vec;

		sort(nums.begin(), nums.end());

		if (nums[0] + nums[1] + nums[2] + nums[3] > target) return vec;
		if (nums[nLen - 1] + nums[nLen - 2] + nums[nLen - 3] + nums[nLen - 4] < target) return vec;

		for (int i = 0; i < nLen - 3; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (nums[i] + nums[nLen - 1] + nums[nLen - 2] + nums[nLen - 3] < target) continue;

			for (int j = i + 1; j < nLen - 2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if (nums[i] + nums[j] + nums[nLen - 1] + nums[nLen - 2] < target) continue;

				int nLeft = j + 1;
				int nRight = nLen - 1;
				while (nLeft < nRight)
				{
					int nSum = nums[i] + nums[j] + nums[nLeft] + nums[nRight];
					if (nSum == target)
					{
						vec.push_back(vector<int>{nums[i], nums[j] , nums[nLeft] , nums[nRight]});
						do { --nRight; } while (nLeft < nRight && nums[nRight] == nums[nRight + 1]);
						do { ++nLeft; } while (nLeft < nRight && nums[nLeft] == nums[nLeft - 1]);
					}
					else if (nSum < target)
					{
						++nLeft;
					}
					else
					{
						--nRight;
					}
				}
			}
		}
		return vec;
	}

	static void test()
	{
		vector<int> a = {0,0,0,0};
		fourSum(a, 0);
	}
};
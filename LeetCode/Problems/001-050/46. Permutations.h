#pragma once
/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
#include <vector>
#include <algorithm>
using std::vector;

class Solution46 {
public:
	static void permuteEx(vector<vector<int>>& result, vector<int>& nums, int nBegin)
	{
		int nLen = nums.size();

		if (nBegin >= nLen)
		{
			result.push_back(nums);
			return;
		}
			
		for (int i = nBegin; i < nLen; ++i)
		{
//			if (i != nBegin && nums[nBegin] == nums[i]) continue;
			swap(nums[nBegin], nums[i]);
			permuteEx(result, nums, nBegin + 1);
			swap(nums[nBegin], nums[i]);
		}
	}

	static vector<vector<int>> permute(vector<int>& nums) {
		// 1 2 3 4 5 6
		// first swap(1,1),  recursion (1)(2 3 4 5 6)
		// second swap(1,2), recursion (2)(1 3 4 5 6)
		// swap(1,3),		 recursion (3)(2 1 4 5 6)
		vector<vector<int>> vecResult;
		sort(nums.begin(), nums.end());
		permuteEx(vecResult, nums, 0);
		return vecResult;
	}

	static void test()
	{
		permute(vector<int>{1, 2, 3, 4});
	}
};
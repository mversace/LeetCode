#pragma once
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/
#include <vector>
#include <map>
#include <algorithm>
using std::vector;
using std::map;

class Solution47 {
public:
	static void permuteEx(vector<vector<int>>& result, vector<int>& nums, int nBegin)
	{
		int nLen = nums.size();

		if (nBegin >= nLen)
		{
			result.push_back(nums);
			return;
		}

		map<int, bool> mapUsed;
		for (int i = nBegin; i < nLen; ++i)
		{
			if (mapUsed[nums[i]]) continue;
			mapUsed[nums[i]] = true;
			swap(nums[nBegin], nums[i]);
			permuteEx(result, nums, nBegin + 1);
			swap(nums[nBegin], nums[i]);
		}
	}

	static vector<vector<int>> permuteUnique(vector<int>& nums) {
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
		permuteUnique(vector<int>{2,2,1,1});
	}
};
#pragma once
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	static void TryAddNum(vector<vector<int>>& v, vector<int>& vt, vector<int>& nums, int nBegin, int nNeed)
	{
		int nLen = (int)nums.size();
		if (nNeed == 0)
		{
			v.push_back(vt);
			return;
		}

		for (int i = nBegin; i < nLen; ++i)
		{
			if (i > nBegin && nums[i] == nums[i - 1]) continue;

			vt.push_back(nums[i]);
			TryAddNum(v, vt, nums, i + 1, nNeed - 1);
			vt.pop_back();
		}
	}
	static vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> v;
		vector<int> vt;
		sort(nums.begin(), nums.end());
		for (int i = 0; i <= (int)nums.size(); ++i)
			TryAddNum(v, vt, nums, 0, i);
		return v;
	}
};
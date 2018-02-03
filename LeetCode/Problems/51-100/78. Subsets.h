#pragma once
/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

*/
#include <vector>
using std::vector;
class Solution78 {
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
			vt.push_back(nums[i]);
			TryAddNum(v, vt, nums, i + 1, nNeed - 1);
			vt.pop_back();
		}
	}
	static vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> v;
		vector<int> vt;
		for (int i = 0; i <= (int)nums.size(); ++i)
			TryAddNum(v, vt, nums, 0, i);
		return v;
	}
	static void test()
	{
		subsets(vector<int>{1,2,3});
	}
};
#pragma once
/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]

*/

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	// [rɪ'kɜːʃ(ə)n]
	void RecursionCheck(vector<vector<int>>& vecResult, vector<int>& candidates, int target, vector<int> vecTemp, int nIdx)
	{
		if (target == 0)
		{
			vecResult.push_back(vecTemp);
			return;
		}

		int nSize = (int)candidates.size();
		for (int i = nIdx; i < nSize; ++i)
		{
			if (target < candidates[i])
				break;

			vecTemp.push_back(candidates[i]);
			RecursionCheck(vecResult, candidates, target - candidates[i], vecTemp, i);
			vecTemp.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> vecResult;
		vector<int> vecTemp;
		RecursionCheck(vecResult, candidates, target, vecTemp, 0);
		return vecResult;
	}
};
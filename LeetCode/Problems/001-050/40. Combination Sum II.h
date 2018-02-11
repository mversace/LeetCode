#pragma once
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
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
			if (i > nIdx && candidates[i] == candidates[i - 1])
				continue;

			vecTemp.push_back(candidates[i]);
			RecursionCheck(vecResult, candidates, target - candidates[i], vecTemp, i + 1);
			vecTemp.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> vecResult;
		vector<int> vecTemp;
		RecursionCheck(vecResult, candidates, target, vecTemp, 0);
		return vecResult;
	}
};
#pragma once
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]

*/
#include <vector>
using std::vector;
class Solution77 {
public:
	static void TryAddNum(vector<vector<int>>& v, vector<int>& vt, int nBegin, int nEnd, int k)
	{
		if ((int)vt.size() == k)
		{
			v.push_back(vt);
			return;
		}
		
		for (int i = nBegin; i <= nEnd; ++i)
		{
			vt.push_back(i);
			TryAddNum(v, vt, i + 1, nEnd, k);
			vt.pop_back();
		}
	}

	static vector<vector<int>> combine(int n, int k) {
		// backtrack
		vector<vector<int>> v;
		vector<int> vt;
		TryAddNum(v, vt, 1, n, k);
		return v;
	}

	static void test()
	{
		combine(4, 2);
	}
};
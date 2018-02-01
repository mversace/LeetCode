#pragma once
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		unordered_map<int, bool> mapCol0;
		int m = (int)matrix.size();
		if (m == 0) return;
		int n = (int)matrix[0].size();
		bool bRow0 = false;
		for (int i = 0; i < m; ++i)
		{
			bRow0 = false;
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					mapCol0[j] = true;
					bRow0 = true;
				}
			}
			if (bRow0)
				memset(&matrix[i][0], 0, sizeof(int) * n);
		}
		for (auto i : mapCol0)
		{
			for (int j = 0; j < m; ++j)
				matrix[j][i.first] = 0;
		}
	}
};
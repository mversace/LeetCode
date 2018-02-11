#pragma once
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/
#include <vector>
using std::vector;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		// 按列把高度累加下来，就和84题一样了，需要逐行遍历
		int r = (int)matrix.size();
		if (r == 0) return 0;
		int c = (int)matrix[0].size();
		if (c == 0) return 0;

		int nMax = 0;
		vector<int> vh(c + 1, 0);
		vh[c] = 0;
		for (int i = 0; i < r; ++i)
		{
			// 计算到i层时的累加高度
			for (int j = 0; j < c; ++j)
			{
				if (matrix[i][j] == '1')
					vh[j]++;
				else
					vh[j] = 0;
			}
			
			// 也就是对vh进行84题的计算
			vector<int> vt;
			for (int j = 0; j < c + 1; ++j)
			{
				while (!vt.empty() && vh[vt.back()] >= vh[j])
				{
					int h = vh[vt.back()];
					vt.pop_back();

					int l = vt.empty() ? -1 : vt.back();
					nMax = max(nMax, (j - l - 1) * h);
				}
				vt.push_back(j);
			}
		}
		return nMax;
	}
};
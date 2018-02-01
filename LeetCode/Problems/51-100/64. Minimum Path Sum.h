#pragma once
/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
[1,5,1],
[4,2,1]]
Given the above grid map, return 7. Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		// DP
		// from 0,0 to x,y
		// dp[x][y] = min(dp[x-1][y], dp[x][y-1]) + dp[x][y];
		int r = (int)grid.size();
		if (r == 0) return 0;
		int c = (int)grid[0].size();
		if (c == 0) return 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (i == 0 && j == 0) continue;
				if (i == 0)
					grid[i][j] += grid[i][j - 1];
				else if (j == 0)
					grid[i][j] += grid[i - 1][j];
				else
					grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
			}
		}
		return grid[r - 1][c - 1];
	}
};
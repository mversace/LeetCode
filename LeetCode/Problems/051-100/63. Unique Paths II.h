#pragma once
/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
#include <vector>
using std::vector;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// use DP
		// dp[x][y] = dp[x+1][y]+dp[x][y+1]
		int n = (int)obstacleGrid.size();
		if (n == 0) return 0;
		int m = (int)obstacleGrid[0].size();
		if (obstacleGrid[n - 1][m - 1] == 1) return 0;

		obstacleGrid[n - 1][m - 1] = 1;
		for (int r = n - 1; r >= 0; --r)
		{
			for (int c = m - 1; c >= 0; --c)
			{
				if (r == n - 1 && c == m - 1)
					continue;

				if (obstacleGrid[r][c] == 1) // obstacle
				{
					obstacleGrid[r][c] = 0;
					continue;
				}

				if (r < n - 1)
					obstacleGrid[r][c] += obstacleGrid[r + 1][c];
				if (c < m - 1)
					obstacleGrid[r][c] += obstacleGrid[r][c + 1];
			}
		}
		return obstacleGrid[0][0];
	}
};
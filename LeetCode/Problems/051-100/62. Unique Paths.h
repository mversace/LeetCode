#pragma once
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
#include <vector>
using std::vector;
class Solution {
public:
	int uniquePaths(int m, int n) {
		// use DP
		// dp[x][y] = dp[x+1][y]+dp[x][y+1]
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[n - 1][m - 1] = 1;
		for (int r = n - 1; r >= 0; --r)
		{
			for (int c = m - 1; c >= 0; --c)
			{
				if (r == n - 1 && c == m - 1)
					continue;

				if (r < n - 1)
					dp[r][c] += dp[r + 1][c];
				if (c < m - 1)
					dp[r][c] += dp[r][c + 1];
			}
		}
		return dp[0][0];
	}
};
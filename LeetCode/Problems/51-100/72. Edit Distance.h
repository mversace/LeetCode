#pragma once
/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
	int minDistance(string word1, string word2) {
		// DP
		// dp[x][y] means steps that convert word1(0..x) to word2(0..y)
		// IF word1[x] == word2[x]  dp[x][y] = dp[x - 1][y - 1]
		// ELSE insert\delete\replace
		// dp[x][y] = 1 + min(dp[x][y - 1], dp[x - 1][y], dp[x - 1][y - 1])
		
		int m = (int)word1.length();
		int n = (int)word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; ++i)
			dp[i][0] = i;
		for (int i = 0; i <= n; ++i)
			dp[0][i] = i;

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			}
		}
		return dp[m][n];
	}
};
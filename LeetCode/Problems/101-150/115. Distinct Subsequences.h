#pragma once
/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
	int numDistinct(string s, string t) {
		// USE DP
		// dp[i][j] means numDistinct(s(0...i - 1) t(0...t - 1))
		// dp[x][0] = 1
		// dp[0][y] = 0 IF(y > 0)
		// dp[i + 1][j + 1]:
		// IF(s[i] == t[j]) dp[i][j] + dp[i][j + 1]   // use s[i] + not use s[i]
		// ELSE dp[i][j + 1]
		int m = (int)s.length();
		int n = (int)t.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < m; ++i)
			dp[i + 1][0] = 1;
		for (int j = 0; j < n; ++j)
			dp[0][j + 1] = 0;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (s[i] == t[j])
					dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
				else
					dp[i + 1][j + 1] = dp[i][j + 1];
			}
		}
		return dp[m][n];
	}
};
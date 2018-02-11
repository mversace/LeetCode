#pragma once
/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// DP
		// dp[x][y]: s2(0...x-1)∫Õs3(0...y-1) «∑Ò∆•≈‰s1
		// dp[0][0] = true;
		// IF x == 0 : dp[x][y] = dp[x][y - 1] && s2[y - 1] == s3[y - 1]
		// IF y == 0 : dp[x][y] = dp[x - 1][y] && s1[x - 1] == s3[x - 1]
		// ELSE : dp[x][y] = dp[x - 1][y] && s1[x - 1] == s3[x + y - 1]) || (dp[x][y - 1] && s2[y - 1] == s3[x + y - 1]);

		int x = (int)s1.length();
		int y = (int)s2.length();
		if ((int)s3.length() != x + y) return false;
		vector<vector<bool>> dp(x + 1, vector<bool>(y + 1, false));
		for (int i = 0; i < x + 1; ++i)
		{
			for (int j = 0; j < y + 1; ++j)
			{
				if (i == 0 && j == 0)
					dp[0][0] = true;
				else if (i == 0)
					dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				else if (j == 0)
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
				else
					dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
			}
		}
		return dp[x][y];
	}
};
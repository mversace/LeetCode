#pragma once
/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution44 {
public:
	static bool isMatch(string s, string p) {
		// this is my first DP solution
		// m = s.length, n = p.length
		// dp[i][j] means if s(0..i-1) fit p(0...j-1). the result = dp[m][n]
		// first set dp[0][0] = true
		// IF((s[i-1]==p[j-1] || p[j-1]=='?') && p[j-1] != '*')
		//     dp[i][j] = dp[i-1][j-1]
		// IF(p[j-1]=='*')
		//     dp[i][j] = dp[i-1][j]   the p[j-1] fit extra char s[i-1]
		//		       || dp[i][j-1]   the p[j-1] don't need fit any char
		// ELSE
		//     dp[i][j] = false

		int m = s.length();
		int n = p.length();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

		// intialize dp[0][0..n]
		dp[0][0] = true;
		int nIdx = 0;
		for (auto c : p)
		{
			if (c != '*') break;
			dp[0][++nIdx] = true;
		}
		
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (p[j] == '*')
					dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
				else if (p[j] == s[i] || p[j] == '?')
					dp[i + 1][j + 1] = dp[i][j];
				else
					dp[i + 1][j + 1] = false;
			}
		}
		
		return dp[m][n];
	}

	static void test()
	{
		isMatch("b", "*?*?");
	}
};
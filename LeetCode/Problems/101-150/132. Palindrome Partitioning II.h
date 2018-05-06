#pragma once
/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
class Solution132 {
public:
	static int minCut(string s) {
		// DP
		// dp[i] means the minCut of s(0...i - 1)
		// pal[i][j] means if s(i...j) is Palindrome
		int len = (int)s.length();
		vector<int> dp(len + 1, 0);
		dp[0] = -1;
		vector<vector<bool>> pal(len, vector<bool>(len, false));
		for (int i = 0; i < len; ++i)
		{
			dp[i + 1] = i;
			for (int j = i; j >= 0; --j)
			{
				// s(i...j) is Palindrome
				if (s[i] == s[j] && (i - j < 2 || pal[j + 1][i - 1]))
				{
					pal[j][i] = true;
					dp[i + 1] = min(dp[i + 1], dp[j] + 1);
				}
			}
		}
		return dp[len];
	}

	static void test()
	{
		//minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
		minCut("aab");
	}
};
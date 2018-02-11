#pragma once
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution91 {
public:
	static int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;

		int n = (int)s.length();
		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 1; i < n; ++i)
		{
			if (s[i] == '0')
			{
				if (s[i - 1] != '1' && s[i - 1] != '2')
					return 0;

				dp[i + 1] = dp[i - 1];
			}
			else if ('1' <= s[i] && s[i] <= '6')
			{
				if (s[i - 1] != '1' && s[i - 1] != '2')
					dp[i + 1] = dp[i];
				else
					dp[i + 1] = dp[i - 1] + dp[i];
			}
			else if ('7' <= s[i] && s[i] <= '9')
			{
				if (s[i - 1] != '1')
					dp[i + 1] = dp[i];
				else
					dp[i + 1] = dp[i - 1] + dp[i];
			}
			else
			{
				return 0;
			}
		}
		return dp[n];
	}

	static void test()
	{
		numDecodings("1111");
	}
};
#pragma once
/*

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#include <string>
#include <vector>
#include <unordered_set>
using std::string;
using std::vector;
using std::unordered_set;
class Solution139 {
public:
	static bool wordBreak(string s, vector<string>& wordDict) {
		// dp[i], 代表s(0...i)符合要求
		// dp[j]: dp[i] = true,且s(i...j)符合
		int nLen = s.length();
		unordered_set<string> st(wordDict.begin(), wordDict.end());
		vector<bool> dp(nLen + 1, false);
		dp[0] = true;
		for (int i = 1; i <= nLen; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (dp[j] && st.count(s.substr(j, i - j)))
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[nLen];
	}

	static void test()
	{
		vector<string> v{"leet","code"};
		wordBreak("leetcode", v);
	}
};
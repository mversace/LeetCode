#pragma once
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
"cats and dog",
"cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
"pine apple pen apple",
"pineapple pen apple",
"pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
#include <vector>
#include <string>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;
class Solution140 {
public:
	static bool TestwordBreak(string s, vector<string>& wordDict) {
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

	static vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (!TestwordBreak(s, wordDict))
			return vector<string>{};

		int nLen = s.length();
		unordered_set<string> st(wordDict.begin(), wordDict.end());
		vector<vector<string>> dp(nLen + 1);
		for (int i = 1; i <= nLen; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if ((j == 0 || !dp[j].empty()) && st.count(s.substr(j, i - j)))
				{
					if (j == 0)
						dp[i].push_back(s.substr(j, i - j));
					else
					{
						for (auto a : dp[j])
							dp[i].push_back(a + " " + s.substr(j, i - j));
					}
				}
			}
		}
		return dp[nLen];
	}

	static void test()
	{
		vector<string> v{ "apple","pen","applepen","pine","pineapple" };
		wordBreak("pineapplepenapple", v);
	}
};
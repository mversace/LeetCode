#pragma once
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution3 {
public:
	static int lengthOfLongestSubstring(string s) {
		string sTemp;
		int nRet = 0;
		for (auto c : s)
		{
			int nPos = (int)sTemp.find(c);
			if (nPos != string::npos)
			{
				nRet = max((int)sTemp.length(), nRet);
				sTemp.erase(0, nPos + 1);
			}
			sTemp.push_back(c);
		}
		nRet = max((int)sTemp.length(), nRet);
		return nRet;
	}

	static void test()
	{
		string s = "dvdf";
		lengthOfLongestSubstring(s);
	}
};
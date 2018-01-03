#pragma once
/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/
#include <string>
using namespace std;

class Solution5 {
public:
	static bool IsPalindrome(string s)
	{
		int nLength = (int)s.length();
		for (int i = 0; i < nLength / 2; ++i)
		{
			if (s[i] != s[nLength - i - 1])
				return false;
		}
		return true;
	}

	static string longestPalindrome(string s) {
		string strRet;
		if (s.empty())
			return strRet;

		int nLength = (int)s.length();
		for (int i = 0; i < nLength; ++i)
		{
			char c = s[i];
			int nPos = (int)s.find_last_of(c);

			int nLenTemp = (nPos - i + 1);
			int nRetLen = (int)strRet.length();
			if (nLenTemp <= nRetLen)
				continue;

			if (nLength - i < nRetLen / 2)
				break;

			string sTemp = s.substr(i, nPos - i + 1);
			while (!sTemp.empty() && nPos != string::npos)
			{
				if (IsPalindrome(sTemp))
				{
					if (sTemp.length() > strRet.length())
					{
						strRet = sTemp;
					}

					break;
				}
				else
				{
					sTemp.pop_back();
					nPos = (int)sTemp.find_last_of(c);

					if (nPos < nRetLen)
						break;

					if (nPos != string::npos)
						sTemp.erase(nPos + 1, sTemp.length() - nPos - 1);
				}
			}
		}

		return strRet;
	}

	static void test()
	{
		string s = longestPalindrome("abcdasdfghjkldcba");

		int i = 0;
	}
};
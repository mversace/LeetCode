#pragma once
/*
	Implement regular expression matching with support for '.' and '*'.

	'.' Matches any single character.
	'*' Matches zero or more of the preceding element.

	The matching should cover the entire input string (not partial).

	The function prototype should be:
	bool isMatch(const char *s, const char *p)

	Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true
*/

#include <string>

using std::string;

class Solution10 {
public:
	static bool isMatch(string s, string p) {
		// 先优化字符串 .*前后的x*都可以去掉
		int nPos = p.find(".*");
		while (nPos < p.length() - 2)
		{
			if (nPos >= 2 && p[nPos - 1] == '*')
			{
				p.erase(nPos - 2, 2);
				nPos -= 2;
			}
			else if (p[nPos + 3] == '*')
				p.erase(nPos + 2, 2);
			else
				nPos = p.find(".*", nPos + 1);
		}

		return isMatchEx(s, p);
	}

	static bool isMatchEx(string s, string p)
	{
		if (s.empty())
		{
			while (p.length() >= 2 && p[1] == '*')
				p.erase(0, 2);

			return p.empty();
		}

		if (p.empty())
			return false;

		if (p.length() == 1)
		{
			return ((p[0] == s[0] || p[0] == '.') && s.length() == 1);
		}

		if (p.length() == 2 && p[1] == '*')
		{
			if (p[0] == '.')
				return true;

			for (auto i : s)
				if (i != p[0])
					return false;

			return true;
		}

		// p.length() >= 2 && s.length() >= 2
		if (p[1] != '*')
		{
			if (p[0] != '.' && p[0] != s[0])
				return false;

			p.erase(p.begin());
			s.erase(s.begin());

			return isMatchEx(s, p);
		}
		else
		{
			char cTemp = p[0];
			string p1 = p.substr(0, 2);
			p.erase(0, 2);

			int nPos = 0;
			bool bHas = false;
			while (nPos <= s.length())
			{
				string s1 = s.substr(0, nPos);
				string s2 = s.substr(nPos, s.length() - nPos);
				bool b1 = isMatchEx(s1, p1);
				bool b2 = isMatchEx(s2, p);
				bHas |= (b1 && b2);

				if (bHas)
					return true;

				++nPos;
			}

			return false;
		}
	}

	static void test()
	{
		bool a = isMatch("bcbabcaacacbcabac","a*c*a*b*.*aa*c*a*a*");
		int n = 0;
	}
};
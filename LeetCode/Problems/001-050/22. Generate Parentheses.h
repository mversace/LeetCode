#pragma once
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution22 {
public:
	void AddChar(vector<string>& vec, string str, int nLeft, int nRight, int nCount)
	{
		if (str.length() == 2 * nCount)
		{
			vec.push_back(str);
			return;
		}

		// ÏÈ¼Ó×óÀ¨ºÅ
		if (nLeft < nCount)
			AddChar(vec, str + "(", nLeft + 1, nRight, nCount);
		if (nRight < nCount && nLeft > nRight)
			AddChar(vec, str + ")", nLeft, nRight + 1, nCount);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> vec;

		AddChar(vec, "", 0, 0, n);

		return vec;
	}
};
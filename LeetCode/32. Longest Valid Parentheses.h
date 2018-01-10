#pragma once
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include <string>
#include <stack>
#include <algorithm>
using std::string;
using std::stack;

class Solution32 {
public:
	static int longestValidParentheses(string s) {
		stack<char> sTemp;
		stack<int> sResult;
		int nLen = s.length();
		for (int i = 0; i < nLen; ++i)
		{
			if (s[i] == ')')
			{
				if (!sTemp.empty() && sTemp.top() == '(')
				{
					sTemp.pop();
					sResult.pop();
				}
				else
				{
					sTemp.push(s[i]);
					sResult.push(i);
				}
					
			}
			else
			{
				sTemp.push(s[i]);
				sResult.push(i);
			}
		}
		if (sResult.empty())
			return nLen;

		int nResult = 0;
		int nR = nLen;
		while (!sResult.empty())
		{
			int nRTemp = sResult.top();
			nResult = max(nResult, nR - nRTemp - 1);
			nR = nRTemp;
			sResult.pop();
		}
		nResult = max(nResult, nR);
		return nResult;
	}

	static void test()
	{
		longestValidParentheses("())");
	}
};
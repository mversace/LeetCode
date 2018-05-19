#pragma once
/*
Given an input string, reverse the string word by word.

Example:

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
#include <string>
#include <stack>
using std::string;
using std::stack;
class Solution151 {
public:
	static void reverseWords(string &s) {
		int i = 0, j = 0;
		stack<string> q;
		while (j < s.length())
		{
			if (s[j] == ' ')
			{
				if (i == j)
				{
					++i;
					++j;
					continue;
				}
				else
				{
					q.push(s.substr(i, j - i));
					i = j;
				}
			}
			else
			{
				++j;
			}
		}
		if (j != i) q.push(s.substr(i, j - i));

		s.clear();
		while (!q.empty())
		{
			if (!s.empty()) s += " ";
			s += q.top();
			q.pop();
		}
	}

	static void test()
	{
		string s = "the sky is blue";
		reverseWords(s);
	}
};
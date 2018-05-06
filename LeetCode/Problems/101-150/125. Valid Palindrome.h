#pragma once
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <string>
using std::string;
class Solution {
public:
	bool isValidChar(char c)
	{
		if ('a' <= c && c <= 'z') return true;
		if ('A' <= c && c <= 'Z') return true;
		if ('0' <= c && c <= '9') return true;
		return false;
	}

	bool isSameChar(char a, char b)
	{
		if (a == b) return true;
		if ('0' <= a && a <= '9') return false;
		if ('0' <= b && b <= '9') return false;
		if (abs(a - b) == 32) return true;
		return false;
	}

	bool isPalindrome(string s) {
		int l = 0;
		int r = (int)s.length() - 1;
		while (l < r)
		{
			if (isValidChar(s[l]) && isValidChar(s[r]))
			{
				if (!isSameChar(s[l], s[r]))
					return false;
				
				++l;
				--r;
			}
			else
			{
				if (!isValidChar(s[l]))
					++l;
				if (!isValidChar(s[r]))
					--r;
			}
		}

		return true;
	}
};
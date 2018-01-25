#pragma once
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution20 {
public:
	bool isValid(string s) {
		vector<char> vec;
		for (auto c : s)
		{
			if (c == '{' || c == '[' || c == '(')
				vec.push_back(c);
			else
			{
				if (vec.empty())
					return false;

				char a = vec.back();
				vec.pop_back();
				switch (c)
				{
				case '}': { if (a != '{') return false; } break;
				case ']': { if (a != '[') return false; } break;
				case ')': { if (a != '(') return false; } break;
				default:
					return false;
				}
			}
		}

		return vec.empty();
	}
};
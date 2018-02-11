#pragma once
/*
Write a function to find the longest common prefix string amongst an array of strings.

// 求最长公共前缀
*/

#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		sort(strs.begin(), strs.end());

		string strOut;
		if (!strs.empty())
		{
			string str1 = strs[0];
			string str2 = strs.back();
			for (int i = 0; i < str1.length() && i < str2.length(); ++i)
			{
				if (str1[i] == str2[i])
					strOut.push_back(str1[i]);
				else
					break;
			}
		}
		return strOut;
	}
};
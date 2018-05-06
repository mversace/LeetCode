#pragma once
/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
["aa","b"],
["a","a","b"]
]
*/
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
public:
	bool IsPalindrome(const string& s, int i, int j)
	{
		while (i < j) if (s[i++] != s[j--]) return false;
		return true;
	}

	void TryPartition(vector<vector<string>>& vv, vector<string>& v, string s, int i)
	{
		if (i == s.length())
		{
			vv.push_back(v);
			return;
		}

		for (int j = i; j < s.length(); ++j)
		{
			if (IsPalindrome(s, i, j))
			{
				v.push_back(s.substr(i, j - i + 1));
				TryPartition(vv, v, s, j + 1);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) 
	{
		vector<vector<string>> vv;
		vector<string> v;
		TryPartition(vv, v, s, 0);
		return vv;
	}
};

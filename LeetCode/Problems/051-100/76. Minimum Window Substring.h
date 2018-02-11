#pragma once
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
class Solution76 {
public:
	static string minWindow(string s, string t) {
		// (0) l,r is the window of s
		// (1) first ++r,check the valid window
		// (2) if valid ++l,get the min window
		unordered_map<char, int> map;
		for (auto c : t) map[c]++;
		int m = (int)s.length();
		int n = (int)t.length();
		int l = 0, r = 0, p = INT_MAX, head = 0;
		while (r < m)
		{
			if (map[s[r++]]-- > 0) --n;
			
			// get valid window
			while (n == 0)
			{
				if (r - l < p)
				{
					p = r - l;
					head = l;
				}
				if (map[s[l++]]++ == 0) ++n;
			}
		}
		string sr;
		if (p != INT_MAX)
			sr = s.substr(head, p);
		return sr;
	}

	static void test()
	{
		minWindow("ab", "a");
	}
};
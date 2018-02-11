#pragma once
/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

great
/    \
gr    eat
/ \    /  \
g   r  e   at
/ \
a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

rgeat
/    \
rg    eat
/ \    /  \
r   g  e   at
/ \
a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

rgtae
/    \
rg    tae
/ \    /  \
r   g  ta  e
/ \
t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
class Solution87 {
public:
	static bool isScramble(string s1, string s2) {
		// Ï¸·Ö£¬µÝ¹é¶Ô±È
		if (s1.length() != s2.length()) return false;
		if (s1 == s2) return true;

		// fuck it. simple check right
		unordered_map<char, int> map;
		for (auto c : s1)
			map[c]++;
		for (auto c : s2)
			map[c]--;
		for (auto m : map)
		{
			if (m.second != 0)
				return false;
		}

		int n = (int)s1.length();
		for (int i = 1; i < n; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
				return true;
		}
		return false;
	}

	static void test()
	{
		bool a = isScramble("abcdefghijklmnopq", "efghijklmnopqcadb");
		int n = 0;
	}
};
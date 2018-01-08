#pragma once
/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

查找s的子串，字串为words中元素的无序链接，返回所有字串的idx
*/

#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> vec;
		if (s.empty() || words.empty())
			return vec;

		int nStep = (int)words[0].length();
		int nItemCount = (int)words.size();
		int nLen = (int)s.length();
		unordered_map<string, int> mapMatch;
		for (auto word : words)
			mapMatch[word]++;

		for (int i = 0; i < nLen - nStep * nItemCount + 1; ++i)
		{
			unordered_map<string, int> mapTemp;
			int j = 0;
			for (; j < nItemCount; ++j)
			{
				string strItem = s.substr(i + j * nStep, nStep);
				if (mapMatch.find(strItem) != mapMatch.end())
				{
					mapTemp[strItem]++;
					if (mapTemp[strItem] > mapMatch[strItem])
						break;
				}
				else
				{
					break;
				}
			}
			if (j == nItemCount)
				vec.push_back(i);
		}
		return vec;
	}
};
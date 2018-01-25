#pragma once
/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vecResult;
		unordered_map<string, vector<string>> mapTemp;
		for (auto s : strs)
		{
			auto sTemp = s;
			sort(sTemp.begin(), sTemp.end());
			mapTemp[sTemp].push_back(s);
		}
		for (auto v : mapTemp)
		{
			vecResult.push_back(v.second);
		}
		return vecResult;
	}
};
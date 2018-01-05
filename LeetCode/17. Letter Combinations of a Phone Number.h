#pragma once
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include <string>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;

class Solution17 {
public:
	static vector<string> letterCombinations(string digits) {
		vector<string> vecResult;
		map<int, string> mapTemp = {{ '2',"abc" },{ '3', "def" },
									{ '4', "ghi" },{ '5', "jkl" },{ '6', "mno" },{ '7', "pqrs" },
									{ '8', "tuv" },{ '9', "wxyz" }};
		for (auto n : digits)
		{
			auto vecTemp = vecResult;
			vecResult.clear();
			for (auto c : mapTemp[n])
			{
				if (vecTemp.empty())
				{
					string a;
					a.push_back(c);
					vecResult.push_back(a);
				}
				else
				{
					for (auto &s : vecTemp)
						vecResult.push_back(s + c);
				}
			}
		}

		return vecResult;
	}

	static void test()
	{
		letterCombinations("2648");
	}
};
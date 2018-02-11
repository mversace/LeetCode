#pragma once
/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution93 {
public:
	static bool IsValid(const string& s)
	{
		if (s.empty() || s.length() > 3) return false;
		if (s.length() == 3)
		{
			if (s[0] > '2') return false;
			if (s[0] == '2' && s[1] > '5') return false;
			if (s[0] == '2' && s[1] == '5' && s[2] > '5') return false;
		}
		if (s[0] == '0' && s.length() > 1) return false;

		return true;
	}

	static void TrySplit(vector<string>& v, string& st, string& s, int nNeed)
	{
		if (nNeed == 1)
		{
			if (IsValid(s))
			{
				st += s;
				v.push_back(st);
			}
			return;
		}

		string s1, s2;
		for (int i = 1; i < 4; ++i)
		{
			if ((int)s.length() < i) break;

			s1 = s.substr(0, i);
			s2 = s.substr(i);
			if (IsValid(s1))
			{
				string stt = st + s1 + ".";
				TrySplit(v, stt, s2, nNeed - 1);
			}
		}
	}

	static vector<string> restoreIpAddresses(string s) {
		vector<string> v;
		if (s.empty() || s.length() > 12)
			return v;

		string st;
		TrySplit(v, st, s, 4);
		return v;
	}

	static void test()
	{
		restoreIpAddresses("000256");
	}
};
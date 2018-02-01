#pragma once
/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include <string>;
using std::string;
class Solution {
public:
	string addBinary(string a, string b) {
		string s;
		int m = (int)a.size() - 1;
		int n = (int)b.size() - 1;
		char c = 0;
		while (m >= 0 || n >= 0 || c > 0)
		{
			c += m >= 0 ? a[m--] - '0' : 0;
			c += n >= 0 ? b[n--] - '0' : 0;
			s.insert(s.begin(), c % 2 + '0');
			c /= 2;
		}
		return s;
	}
};
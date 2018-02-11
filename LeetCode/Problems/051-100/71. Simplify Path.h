#pragma once
/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
using std::istringstream;
class Solution {
public:
	string simplifyPath(string path) {
		string s;
		vector<string> vecS;
		istringstream ss(path);
		while (getline(ss, s, '/'))
		{
			if (s == "." || s == "") continue;
			if (s == "..")
			{
				if (!vecS.empty()) vecS.pop_back();
			}
			else
			{
				vecS.push_back(s);
			}
		}
		s = "";
		for (auto st : vecS)
			s += "/" + st;
		return s.empty() ? "/" : s;
	}
};
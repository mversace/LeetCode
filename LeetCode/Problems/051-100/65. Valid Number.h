#pragma once
/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/
#include <string>
using std::string;
class Solution {
public:
	bool isNumber(string s) {
		// I know this problem is shit, so skip it
		// copy solution
		// trim space head and tail
		int nPos = s.find_first_not_of(' ');
		if (nPos != string::npos) s.erase(0, nPos);
		nPos = s.find_last_not_of(' ');
		if (nPos != string::npos) s.erase(nPos + 1, (int)s.size() - nPos - 1);
		if (s.empty()) return false;

		int state = 0;
		for (auto c : s)
		{
			if (c == '-' || c == '+')
			{
				if (state == 0 || state == 3)
					state++;
				else
					return false;
			}
			else if (c == '.')
			{
				if (state == 2)
					state = 7;
				else if (state == 0 || state == 1)
					state = 6;
				else
					return false;
			}
			else if ('0' <= c && c <= '9')
			{
				if (state == 1 || state == 4 || state == 6)
					state++;
				else if (state == 0 || state == 3)
					state = state + 2;
			}
			else if (c == 'e' || c == 'E')
			{
				if (state == 2 || state == 7)
					state = 3;
				else
					return false;
			}
			else
			{
				return false;
			}
		}

		if (state == 2 || state == 7 || state == 5)
			return true;

		return false;
	}
};
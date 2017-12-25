#pragma once
/*

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
#include <string>
using namespace std;

class Solution8 {
public:
	static int myAtoi(string str) {
		if (str.empty()) return 0;
		long long nRet = 0;
		int nSignal = 1;
		bool bHasChar = false;
		for (auto i : str)
		{
			if (i == ' ' && !bHasChar) continue;

			if ('0' <= i && i <= '9')
			{
				bHasChar = true;
				nRet = nRet * 10 + i - '0';

				if (nRet * nSignal > INT_MAX)
					return INT_MAX;

				if (nRet * nSignal < INT_MIN)
					return INT_MIN;
			}
			else if (i == '-' || i == '+')
			{
				if (bHasChar) return 0;

				bHasChar = true;
				if (i == '-')
					nSignal *= -1;
			}
			else
			{
				return int(nSignal * nRet);;
			}
		}

		return int(nSignal * nRet);
	}

	static void test()
	{
		myAtoi("-2147483648");
	}
};
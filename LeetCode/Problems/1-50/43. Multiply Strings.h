#pragma once
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <string>
using std::string;

class Solution43 {
public:
	// violence loop
	// abcde * abc = abcde*a + abcde*b + abcde*c
	static string multiply(string num1, string num2) {
		int nLen1 = (int)num1.length();
		int nLen2 = (int)num2.length();
		string strResult(nLen1 + nLen2, '0');

		for (int i = 0; i < nLen2; ++i)
		{
			char c = num2.back();
			num2.pop_back();

			int nBeginIdx = nLen1 + nLen2 - 1 - i;
			for (int j = 0; j < nLen1; ++j, --nBeginIdx)
			{
				int nX = (c - '0') * (num1[nLen1 - j - 1] - '0');

				int nIdx = nBeginIdx;
				while (nX)
				{
					nX += strResult[nIdx] - '0';
					strResult[nIdx--] = nX % 10 + '0';
					nX = nX / 10;
				}
			}
		}

		int nPos = strResult.find_first_not_of('0');
		if (nPos == string::npos)
			return "0";

		strResult.erase(0, nPos);
		return strResult;
	}

	static void test()
	{
		multiply("12154", "78521");
	}
};
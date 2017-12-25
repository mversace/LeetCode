#pragma once
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include <string>

using namespace std;

class Solution6 {
public:
	static string convert(string s, int numRows) {
		if (s.empty()) return "";
		if (numRows == 1) return s;

		string strRet;
		int nItemNum = numRows * 2 - 2;
		int nSize = s.length();
		for (int i = 0; i < numRows; ++i)
		{
			int nPos = i;
			while (nPos < nSize)
			{
				strRet += s[nPos];

				if (0 < i && i < numRows - 1)
				{
					int nTemp = nPos + nItemNum - i * 2;
					if (nTemp >= nSize)
						break;

					strRet += s[nTemp];
				}

				nPos += nItemNum;
			}
		}

		return strRet;
	}

	static void test()
	{
		convert("ABCD", 3);
	}
};
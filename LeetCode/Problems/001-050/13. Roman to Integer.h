#pragma once
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）。记数的方法：
1.相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
2.小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
3.小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；
4.在一个数的上面画一条横线，表示这个数增值 1,000 倍
*/

#include <string>
using std::string;

class Solution13 {
public:
	int romanToInt(string s) {
		int n = 0;
		int nLen = s.length();
		for (int i = 0; i < nLen; ++i)
		{
			switch (s[i])
			{
			case 'I':
			{
				if (i < nLen - 1 && (s[i + 1] == 'X' || s[i + 1] == 'V'))
					n -= 1;
				else
					n += 1;
				break;
			}
			case 'X':
			{
				if (i < nLen - 1 && (s[i + 1] == 'C' || s[i + 1] == 'L'))
					n -= 10;
				else
					n += 10;
				break;
			}
			case 'C':
			{
				if (i < nLen - 1 && (s[i + 1] == 'M' || s[i + 1] == 'D'))
					n -= 100;
				else
					n += 100;
				break;
			}
			case 'M': n += 1000; break;
			case 'V': n += 5; break;
			case 'L': n += 50; break;
			case 'D': n += 500; break;
			}
		}
		return n;
	}
};
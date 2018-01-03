#pragma once
/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

 Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）。记数的方法：
1.相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
2.小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
3.小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；
4.在一个数的上面画一条横线，表示这个数增值 1,000 倍

*/
#include <string>
using std::string;

class Solution12 {
public:
	static string intToRoman(int num) {
		string strResult;
		
		int nTemp = num / 1000;
		while (nTemp--) strResult += "M";
		
		nTemp = num % 1000 / 100;
		switch (nTemp)
		{
		case 1: strResult += "C"; break;
		case 2: strResult += "CC"; break;
		case 3: strResult += "CCC"; break;
		case 4: strResult += "CD"; break;
		case 5: strResult += "D"; break;
		case 6: strResult += "DC"; break;
		case 7: strResult += "DCC"; break;
		case 8: strResult += "DCCC"; break;
		case 9: strResult += "CM"; break;
		}

		nTemp = num % 100 / 10;
		switch (nTemp)
		{
		case 1: strResult += "X"; break;
		case 2: strResult += "XX"; break;
		case 3: strResult += "XXX"; break;
		case 4: strResult += "XL"; break;
		case 5: strResult += "L"; break;
		case 6: strResult += "LX"; break;
		case 7: strResult += "LXX"; break;
		case 8: strResult += "LXXX"; break;
		case 9: strResult += "XC"; break;
		}
		nTemp = num % 10;
		switch (nTemp)
		{
		case 1: strResult += "I"; break;
		case 2: strResult += "II"; break;
		case 3: strResult += "III"; break;
		case 4: strResult += "IV"; break;
		case 5: strResult += "V"; break;
		case 6: strResult += "VI"; break;
		case 7: strResult += "VII"; break;
		case 8: strResult += "VIII"; break;
		case 9: strResult += "IX"; break;
		}
		return strResult;
	}

	static void test()
	{

	}
};
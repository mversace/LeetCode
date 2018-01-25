#pragma once
/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

 ��1����X��10����C��100����M��1000����V��5����L��50����D��500���������ķ�����
1.��ͬ��������д������ʾ����������Щ������ӵõ��������� ��=3��
2.С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ��������� ��=8����=12��
3.С�����֣����� ��X �� C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ��������� ��=4����=9��
4.��һ���������滭һ�����ߣ���ʾ�������ֵ 1,000 ��

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
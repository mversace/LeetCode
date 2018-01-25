#pragma once
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

��1����X��10����C��100����M��1000����V��5����L��50����D��500���������ķ�����
1.��ͬ��������д������ʾ����������Щ������ӵõ��������� ��=3��
2.С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ��������� ��=8����=12��
3.С�����֣����� ��X �� C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ��������� ��=4����=9��
4.��һ���������滭һ�����ߣ���ʾ�������ֵ 1,000 ��
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
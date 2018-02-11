#pragma once
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
#include <string>
using std::string;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		if (haystack.empty())
			return -1;

		int nLenHay = (int)haystack.length();
		int nLenNeed = (int)needle.length();
		for (int i = 0; i < nLenHay - nLenNeed + 1; ++i)
		{
			int nLeft = i;
			int nRight = nLeft + nLenNeed - 1;
			while (nLeft < nRight && haystack[nLeft] == needle[nLeft - i] && haystack[nRight] == needle[nRight - i])
			{
				++nLeft;
				--nRight;
			}
			if (nLeft > nRight)
				return i;

			if (nLeft == nRight && haystack[nLeft] == needle[nLeft - i])
				return i;
		}
		return -1;
	}
};
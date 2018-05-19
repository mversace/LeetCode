#pragma once
/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/
#include <string>
using std::string;
class Solution165 {
public:
	static int compareVersion(string version1, string version2) {
		int i = 0;
		int j = 0;
		int n1 = (int)version1.size();
		int n2 = (int)version2.size();

		int num1 = 0;
		int num2 = 0;
		while (i < n1 || j < n2)
		{
			while (i < n1 && version1[i] != '.') {
				num1 = num1 * 10 + (version1[i] - '0');
				i++;
			}

			while (j < n2 && version2[j] != '.') {
				num2 = num2 * 10 + (version2[j] - '0');;
				j++;
			}

			if (num1 > num2) return 1;
			else if (num1 < num2) return -1;

			num1 = 0;
			num2 = 0;
			i++;
			j++;
		}

		return 0;
	}

	static void test()
	{
		compareVersion("01", "1");
	}
};
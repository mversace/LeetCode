#pragma once
/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
#include <algorithm>

class Solution50 {
public:
	static double myPow(double x, int n) {
		if (n == 0)
			return 1;

		double xEx = 1.0;
		unsigned long long m = abs(n);
		if (n < 0)
			x = 1 / x;
		while (m >= 2)
		{
			if (m % 2)
				xEx *= x * (m % 2);
			
			x *= x;
			m /= 2;
		}

		return (x * xEx);
	}

	static void test()
	{
		myPow(2.0, -2147483647);
	}
};
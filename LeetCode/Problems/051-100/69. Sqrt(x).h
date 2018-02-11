#pragma once
/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
*/

class Solution69 {
public:
	static int mySqrt(int x) {
		// Newton's Method
		// f(a) = a*a - x; find a=?
		// f'(a) = 2a;
		// set a = x/2 then next value b
		// b = a - f(a)/f'(a)
		// b = a - (a*a - x)/(2a)
		// b = 1/2 * (a + x/a)

		if (x <= 1) return x;
		double a = (double)x / 2.0;
		double b = a;
		while (true)
		{
			b = a;
			a = (a + (double)x / a) / 2.0;
			if (abs(a - b) <= 0.01)
				break;
		}

		return int(a);
	}
	static void test()
	{
		mySqrt(1);
	}
};
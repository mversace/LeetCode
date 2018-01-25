#pragma once
/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

#include <limits.h>

class Solution29 {
public:
	static int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		if (divisor == 1) return dividend;
		if (divisor == -1)
		{
			if (dividend == INT_MIN)
				return INT_MAX;

			return -dividend;
		}

		int nResult = 0;
		
		long long llDividend = labs(dividend);
		long long llDivisor = labs(divisor);

		while (llDividend >= llDivisor)
		{
			long long llTemp = llDivisor;
			long long llTempEx = 1;
			while (llDividend >= (llTemp << 1))
			{
				llTemp <<= 1;
				llTempEx <<= 1;
			}
			llDividend -= llTemp;
			nResult += (int)llTempEx;
		}

		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			return -nResult;

		return nResult;
	}

	static void test()
	{
		divide(2147483647, 3);
	}
};
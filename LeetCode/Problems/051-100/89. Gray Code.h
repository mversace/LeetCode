#pragma once
/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
#include <vector>
using std::vector;
class Solution89 {
public:
	static vector<int> grayCode(int n) {
		// sorry ni da ye
		// n=3 000 001 011 010 110 111 101 100
		vector<int> v;
		v.push_back(0);

		for (int i = 0; i < n; ++i)
		{
			int fuck = (int)v.size() - 1;
			while (fuck >= 0)
			{
				v.push_back((1 << i) + v[fuck--]);
			}
		}

		return v;
	}

	static void test()
	{
		grayCode(3);
	}
};
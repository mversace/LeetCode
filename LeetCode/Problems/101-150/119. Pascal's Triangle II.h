#pragma once
/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
using std::vector;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v(rowIndex + 1, 0);
		for (int i = 0; i < rowIndex + 1; ++i)
		{
			for (int j = i; j >= 0; --j)
			{
				if (j == 0 || j == i || i == 0)
					v[j] = 1;
				else
					v[j] = v[j] + v[j - 1];
			}
		}
		return v;
	}
};
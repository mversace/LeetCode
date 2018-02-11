#pragma once
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.
*/
#include <vector>
using std::vector;
class Solution74 {
public:
	static bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int l = 0, t = 0;
		if (matrix.empty()) return false;
		int b = (int)matrix.size() - 1;
		if (matrix[0].empty()) return false;
		int r = (int)matrix[0].size() - 1;
		while (t < b)
		{
			int m = (t + b) / 2;

			if (matrix[m][r] < target)
				t = m + 1;
			else if (matrix[m][0] > target)
				b = m - 1;
			else
				t = b = m;
		}
		if (matrix[t][0] <= target && target <= matrix[t][r])
		{
			while (l < r)
			{
				int m = (l + r) / 2;
				if (matrix[t][m] == target)
					return true;

				if (matrix[t][m] < target)
					l = m + 1;
				else
					r = m;
			}
			if (matrix[t][l] == target)
				return true;
		}

		return false;
	}

	static void test()
	{
		searchMatrix(vector<vector<int>>{ {1}, {3}}, 1);
	}
};

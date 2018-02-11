#pragma once
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include <vector>
using std::vector;
class Solution54 {
public:
	static vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> vec;
		int nRows = (int)matrix.size();
		if (nRows == 0)
			return vec;

		int nCols = (int)matrix[0].size();
		if (nCols == 0)
			return vec;

		int n = 0; // 0¡ú 1¡ý 2¡û 3¡ü
		int x = 0, y = 0;
		int l = nCols - 1;
		for (int i = 0; i < nRows * nCols; ++i)
		{
			vec.push_back(matrix[x][y]);

			switch (n)
			{
			case 0: if (y == l) { n = (++n) % 4; l = nRows - 1 - x; ++x; }
					else { ++y; } break;
			case 1: if (x == l) { n = (++n) % 4; l = nCols - 1 - y; --y; }
					else { ++x; } break;
			case 2: if (y == l) { n = (++n) % 4; l = nRows - 1 - x + 1; --x; }
					else { --y; } break;
			case 3: if (x == l) { n = (++n) % 4; l = nCols - 1 - y - 1; ++y; }
					else { --x; } break;
			}
		}

		return vec;
	}

	static void test()
	{
		spiralOrder(vector<vector<int>>{ {1, 2, 3, 4}, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }});
	}
};
#pragma once
/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/
#include <vector>
using std::vector;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> vec(n, vector<int>(n, 0));

		int nDir = 0; // 0¡ú 1¡ý 2¡û 3¡ü
		int x = 0, y = 0;
		int l = n - 1;
		for (int i = 0; i < n * n; ++i)
		{
			vec[x][y] = i + 1;

			switch (nDir)
			{
			case 0: if (y == l) { nDir = (++nDir) % 4; l = n - 1 - x; ++x; }
					else { ++y; } break;
			case 1: if (x == l) { nDir = (++nDir) % 4; l = n - 1 - y; --y; }
					else { ++x; } break;
			case 2: if (y == l) { nDir = (++nDir) % 4; l = n - 1 - x + 1; --x; }
					else { --y; } break;
			case 3: if (x == l) { nDir = (++nDir) % 4; l = n - 1 - y - 1; ++y; }
					else { --x; } break;
			}
		}

		return vec;
	}
};
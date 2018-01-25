#pragma once
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
[1,2,3],
[4,5,6],
[7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
[7,4,1],
[8,5,2],
[9,6,3]
]
Example 2:

Given input matrix =
[
[ 5, 1, 9,11],
[ 2, 4, 8,10],
[13, 3, 6, 7],
[15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
[15,13, 2, 5],
[14, 3, 4, 1],
[12, 6, 8, 9],
[16, 7,10,11]
]
*/
#include <vector>
using std::vector;
class Solution48 {
public:
	static void rotate(vector<vector<int>>& matrix) {
		// assume the matrix is valid
		int nLen = matrix.size();
		for (int i = 0; i < (nLen + 1) / 2; ++i)
		{
			for (int j = i; j < nLen - i - 1; ++j)
			{
				// 0 0 to 0 nLen-1
				// 0 1 to 1 nLen-1
				// 1 0 to 0 nLen-1-1
				// 1 1 to 1 nLen-1-1
				swap(matrix[i][j], matrix[j][nLen - 1 - i]); 
				swap(matrix[i][j], matrix[nLen - 1 - i][nLen - 1 - j]);
				swap(matrix[i][j], matrix[nLen - 1 - j][i]);
			}
		}
	}

	static void test()
	{
		vector<vector<int>> vec = 
		{
			{5, 1, 9, 11},
			{2, 4, 8, 10},
			{13, 3, 6, 7},
			{15, 14, 12, 16}
		};

		rotate(vec);
	}
};
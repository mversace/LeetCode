#pragma once
/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
	 [1],
	[1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

#include <vector>
using std::vector;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v;
		for (int i = 0; i < numRows; ++i)
		{
			vector<int> vt;
			for (int j = 0; j < i + 1; ++j)
			{
				if (j == 0 || j == i || i == 0)
					vt.push_back(1);
				else
					vt.push_back(v[i - 1][j - 1] + v[i - 1][j]);
			}
			v.push_back(vt);
		}
		return v;
	}
};
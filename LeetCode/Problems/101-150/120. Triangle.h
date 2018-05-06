#pragma once
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
		[2],
	   [3,4],
	  [6,5,7],
	 [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		vector<int> dp((int)triangle.size(), 0);
		for (int i = 0; i < (int)triangle.size(); ++i)
		{
			for (int j = (int)triangle[i].size() - 1; j >= 0; --j)
			{
				if (i == 0) dp[j] = triangle[i][j];
				else if (j == 0) dp[j] += triangle[i][j];
				else if (j == (int)triangle[i].size() - 1) dp[j] = triangle[i][j] + dp[j - 1];
				else dp[j] = triangle[i][j] + min(dp[j - 1], dp[j]);
			}
		}
		sort(dp.begin(), dp.end());
		return dp[0];
	}
};
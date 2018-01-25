#pragma once
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	int trap(vector<int>& height) {
		int nLeft = 0;
		int nRight = (int)height.size() - 1;
		int nResult = 0;
		int nLeftMax = 0;
		int nRightMax = 0;
		while (nLeft <= nRight)
		{
			nLeftMax = max(nLeftMax, height[nLeft]);
			nRightMax = max(nRightMax, height[nRight]);
			if (nLeftMax <= nRightMax)
			{
				nResult += nLeftMax - height[nLeft];
				++nLeft;
			}
			else
			{
				nResult += nRightMax - height[nRight];
				--nRight;
			}
		}
		return nResult;
	}
};
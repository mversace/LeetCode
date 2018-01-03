#pragma once
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <vector>
#include <windows.h>

using std::vector;

class Solution11 {
public:
	static int maxArea(vector<int>& height) {
		int nMax = 0;
		int i = 0, j = (int)height.size() - 1;

		while (i < j)
		{
			int h = min(height[i], height[j]);
			nMax = max(nMax, (j - i) * h);
			while (i < j && height[i] <= h)
				++i;
			while (i < j && height[j] <= h)
				--j;
		}
		
		return nMax;
	}

	static void test()
	{
		vector<int> a = { 1, 1 };
		maxArea(a);
	}
};
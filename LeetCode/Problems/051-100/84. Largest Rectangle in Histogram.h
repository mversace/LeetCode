#pragma once
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/
#include <vector>
using std::vector;
class Solution84 {
public:
	static int largestRectangleArea(vector<int>& heights) {
		// 对于坐标x点，设置以heights[x]为矩形高度的面积为M
		// 计算M需要向左和向右查找>=heights[x]的柱子，然后相乘
		// 但此办法遇到N个1的vector时会超时，因为循环太多

		// 把每个点全部存入vt，如果发现当前高度低于上一个高度时
		// 取出上一个点，并计算以此点为高度的矩形大小
		// 保证最终vt中是顺序排列的高度，最后计算vt中剩余的巨型
		heights.push_back(0); // 可以循环到最后
		int n = (int)heights.size();
		int nMax = 0;
		vector<int> vt;
		for (int i = 0; i < n; ++i)
		{
			while (!vt.empty() && heights[vt.back()] >= heights[i])
			{
				int h = heights[vt.back()];
				vt.pop_back();

				int l = vt.empty() ? -1 : vt.back();
				nMax = max(nMax, (i - l - 1) * h);
			}
			vt.push_back(i);
		}

		return nMax;
	}

	static void test()
	{
		largestRectangleArea(vector<int>{1,1});
	}
};
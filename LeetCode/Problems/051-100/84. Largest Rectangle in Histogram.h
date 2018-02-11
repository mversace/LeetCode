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
		// ��������x�㣬������heights[x]Ϊ���θ߶ȵ����ΪM
		// ����M��Ҫ��������Ҳ���>=heights[x]�����ӣ�Ȼ�����
		// ���˰취����N��1��vectorʱ�ᳬʱ����Ϊѭ��̫��

		// ��ÿ����ȫ������vt��������ֵ�ǰ�߶ȵ�����һ���߶�ʱ
		// ȡ����һ���㣬�������Դ˵�Ϊ�߶ȵľ��δ�С
		// ��֤����vt����˳�����еĸ߶ȣ�������vt��ʣ��ľ���
		heights.push_back(0); // ����ѭ�������
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
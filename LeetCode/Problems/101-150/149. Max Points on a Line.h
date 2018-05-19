#pragma once
/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
using std::vector;
using std::map;
class Solution149 {
public:
	struct Point {
		int x;
		int y;
		Point() : x(0), y(0) {}
		Point(int a, int b) : x(a), y(b) {}
	};

	static int GCD(int a, int b) {

		if (b == 0) return a;
		else return GCD(b, a % b);
	}

	static int maxPoints(vector<Point>& points) {
		int nLen = (int)points.size();
		int nMax = 0;
		for (int i = 0; i < nLen; ++i)
		{
			int nSamePoint = 1;
			map<std::pair<int, int>, int> mapPtNums;
			for (int j = i + 1; j < nLen; ++j)
			{
				if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					++nSamePoint;
				}
				else if (points[i].y == points[j].y)
				{
					mapPtNums[std::make_pair(100, 100)]++;
				}
				else
				{
					int y = points[i].y - points[j].y;
					int x = points[i].x - points[j].x;
					int n = GCD(x, y);
					y /= n;
					x /= n;
					mapPtNums[std::make_pair(y, x)]++;
				}
			}
			int nTemp = 0;
			for (auto it : mapPtNums)
				nTemp = max(nTemp, it.second);
			nTemp += nSamePoint;
			nMax = max(nMax, nTemp);
		}
		return nMax;
	}

	static void test()
	{
		vector<Point> v{{0,0 }, { 94911151,94911150 }, { 94911152,94911151 }};
		maxPoints(v);
	}
};
#pragma once
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include <vector>
#include <algorithm>
using std::vector;
// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> vec;
		sort(intervals.begin(), intervals.end(), [](Interval& one, Interval& two) { return one.start < two.start; });
		
		for (auto i : intervals)
		{
			auto it = vec.end() - 1;
			if (vec.empty() || i.start > it->end)
				vec.push_back(i);
			else
			{
				it->end = max(it->end, i.end);
			}
		}
		return vec;
	}
};
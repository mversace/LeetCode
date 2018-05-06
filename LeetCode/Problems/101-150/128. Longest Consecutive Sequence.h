#pragma once
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
#include <vector>
#include <set>
using std::vector;
using std::set;
class Solution128 {
public:
	static int longestConsecutive(vector<int>& nums) {
		if (nums.empty()) return 0;
		set<int> s(nums.begin(), nums.end());
		int n = 1;
		int nMax = 1;
		int nPre = 0;
		for (auto i = s.begin(); i != s.end(); ++i)
		{
			if (i != s.begin())
			{
				if (*i - nPre == 1)
				{
					++n;
				}
				else
				{
					nMax = max(n, nMax);
					n = 1;
				}
			}
			nPre = *i;
		}

		return max(n, nMax);
	}

	static void test()
	{
		vector<int> v{0, -1};
		longestConsecutive(v);
	}
};
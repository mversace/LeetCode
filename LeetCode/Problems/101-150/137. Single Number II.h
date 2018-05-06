#pragma once
/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_multiset;
class Solution137 {
public:
	static int singleNumber(vector<int>& nums) {
		unordered_multiset<int> s(nums.begin(), nums.end());
		for (auto i : s)
		{
			if (s.count(i) == 1)
				return i;
		}
		return -1;
	}

	static void test()
	{
		vector<int> v{ -2,-2,1,1,-3,1,-3,-3,-4,-2 };
		singleNumber(v);
	}
};
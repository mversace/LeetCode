#pragma once
/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ¡Ù nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -¡Þ.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
*/
#include <vector>
using std::vector;
class Solution162 {
public:
	static int TryFindPeak(vector<int>& nums, int l, int r)
	{
		if (l == r) return l;
		int m = (l + r) / 2;
		if (nums[m] > nums[m + 1])
			return TryFindPeak(nums, l, m);
		return TryFindPeak(nums, m + 1, r);
	}
	static int findPeakElement(vector<int>& nums) {
		return TryFindPeak(nums, 0, (int)nums.size() - 1);
	}

	static void test()
	{
		vector<int> v{1,2,3,1};
		findPeakElement(v);
	}
};
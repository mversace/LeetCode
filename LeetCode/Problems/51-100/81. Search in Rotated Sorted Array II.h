#pragma once
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/
#include <vector>
using std::vector;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int l = 0;
		int r = (int)nums.size() - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums[m] == target) return true;
			
			if (nums[m] < nums[r])
			{
				if (nums[m] < target && nums[r] >= target)
					l = m + 1;
				else
					r = m - 1;
			}
			else if (nums[m] > nums[r])
			{
				if (nums[m] > target && nums[l] <= target)
					r = m - 1;
				else
					l = m + 1;
			}
			else
			{
				--r;
			}
		}
		return false;
	}
};
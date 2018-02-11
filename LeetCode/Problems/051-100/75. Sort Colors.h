#pragma once
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution75 {
public:
	static void sortColors(vector<int>& nums) {
		// l : 0's end + 1
		// r : 2's first - 1
		int l = 0, m = 0;
		int r = (int)nums.size() - 1;
		while (m <= r)
		{
			if (nums[m] == 0)
			{
				swap(nums[l], nums[m]);
				++l;
				++m;
			}
			else if (nums[m] == 1)
			{
				++m;
			}
			else if (nums[m] == 2)
			{
				swap(nums[m], nums[r]);
				--r;
			}
		}
	}

	static void test()
	{
		sortColors(vector<int>{ 1,0 });
	}
};
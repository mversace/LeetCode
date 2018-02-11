#pragma once
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include <vector>
using std::vector;

class Solution33 {
public:
	static int search(vector<int>& nums, int target) {
		int nLeft = 0;
		int nRight = (int)nums.size() - 1;
		while (nLeft <= nRight)
		{
			if (nums[nLeft] == target) return nLeft;
			if (nums[nRight] == target) return nRight;

			int nMid = (nLeft + nRight) / 2;

			if (nums[nMid] == target) return nMid;

			if (nums[nMid] > target)
			{
				if (nums[nLeft] < target || 
					(nums[nRight] > nums[nMid] && nums[nRight] > target))
				{
					++nLeft;
					nRight = nMid;
				}
				else
				{
					--nRight;
					nLeft = nMid;
				}
			}
			else
			{
				if (nums[nRight] > target ||
					(nums[nRight] < nums[nMid] && nums[nRight] < target))
				{
					--nRight;
					nLeft = nMid;
				}
				else
				{
					++nLeft;
					nRight = nMid;
				}
			}
		}
		return -1;
	}

	static void test()
	{
		vector<int> v = {5,1,2,3,4};
		int n = search(v, 1);
		int m = 0;
	}
};
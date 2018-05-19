#pragma once
/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0, r = (int)nums.size() - 1;
		int nMin = INT_MAX;
		while (l <= r)
		{
			while (l < r && nums[l] == nums[r]) ++l;
			while (l < r && nums[l] == nums[r]) --r;
			int m = (l + r) / 2;
			nMin = min(nums[l], nMin);
			nMin = min(nums[m], nMin);
			nMin = min(nums[r], nMin);

			// 12345 23451 34512 45123 51234
			// 1234 2341 3412 4123
			if (nums[m] >= nums[l] && nums[m] >= nums[r])
			{
				// 最小值在右边
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}

		return nMin;
	}
};
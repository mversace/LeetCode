#pragma once
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

给定一个序列，排序，返回一个刚刚比给定序列大的序列，没有返回升序序列
*/

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int nLen = (int)nums.size() - 1;
		for (int i = nLen; i > 0; --i)
		{
			if (nums[i] > nums[i - 1])
			{
				for (int j = nLen; j >= i; --j)
				{
					if (nums[j] > nums[i - 1])
					{
						int nTemp = nums[j];
						nums[j] = nums[i - 1];
						nums[i - 1] = nTemp;

						sort(nums.begin() + i, nums.end());
						return;
					}
				}
			}
		}
		sort(nums.begin(), nums.end());
	}
};
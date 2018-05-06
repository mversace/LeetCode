#pragma once
/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/
#include <vector>
using std::vector;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// 异或两次为原值
		int n = nums[0];
		for (int i = 1; i < (int)nums.size(); ++i)
			n ^= nums[i];
		return n;
	}
};
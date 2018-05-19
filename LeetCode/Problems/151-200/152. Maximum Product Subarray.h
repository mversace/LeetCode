#pragma once
/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <vector>
#include <utility>
using std::vector;
class Solution152 {
public:
	static int maxProduct(vector<int>& nums) {
		int nLen = (int)nums.size();
		if (nLen == 0) return 0;
// 		vector<int> dpMax(nLen, 0); // dpMax[i] 以i结尾的subarray的最大product
// 		vector<int> dpMin(nLen, 0); // 最小
		int nMaxResult = nums[0];

		for (int i = 1, nMax = nums[0], nMin = nums[0]; i < nLen; ++i)
		{
			if (nums[i] < 0)
				std::swap(nMax, nMin);

			nMax = max(nMax * nums[i], nums[i]);
			nMin = min(nMin * nums[i], nums[i]);
			nMaxResult = max(nMaxResult, nMax);
		}
		return nMaxResult;
	}

	static void test()
	{
		vector<int> v{-4, -3, -2};
		vector<int> vv{1, -1, 2, 3, -2, 4};
		maxProduct(v);
		maxProduct(vv);
	}
};
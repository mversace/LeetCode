#pragma once
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution53 {
public:
	static int maxSubArray(vector<int>& nums) {
		// use DP
		// dp[i] means the contiguous subarray that end with nums[i] and has the largest sum
		// dp[i] = nums[i] + dp[i - 1] > 0 ? dp[i - 1] : 0

		int nLen = (int)nums.size();
		if (nLen == 0)
			return 0;

		vector<int> dp(nLen, 0);
		dp[0] = nums[0];

		int nMax = dp[0];
		for (int i = 1; i < nLen; ++i)
		{
			dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
			nMax = max(nMax, dp[i]);
		}
		return nMax;
	}

	static void test()
	{
		maxSubArray(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4});
	}
};
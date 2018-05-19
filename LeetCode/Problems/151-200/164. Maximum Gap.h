#pragma once
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
(3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution164 {
public:
	static int maximumGap(vector<int>& nums) {
		// 对于n个数字来说，取出最小min和最大max，那么可知 gap >= (max-min)/(n-1)
		// 那么可以采用桶排序，桶大小范围为 [0, (max-min)/(n-1))
		// 例如 0 10 20，桶范围为(20-0)/(3-1)=10,那么桶内的最大gap为(max-min)/(n-1)-1
		// 此时对比桶之间的差距即可
		if ((int)nums.size() <= 1) return 0;
		int nMin = INT_MAX, nMax = INT_MIN;
		for (auto i : nums)
		{
			nMin = min(nMin, i);
			nMax = max(nMax, i);
		}

		if (nMin == nMax) return 0;

		int nSize = (int)nums.size();
		int nBucketRange = max(1, (nMax - nMin) / (nSize - 1));
		int nBucketCount = (nMax - nMin) / nBucketRange + 1;
		vector<int> vecMin(nBucketCount, INT_MAX);
		vector<int> vecMax(nBucketCount, INT_MIN);
		vector<int> vecBucketNums(nBucketCount, 0);
		for (auto i : nums)
		{
			int nBucketId = (i - nMin) / nBucketRange;
			vecMin[nBucketId] = min(vecMin[nBucketId], i);
			vecMax[nBucketId] = max(vecMax[nBucketId], i);
			vecBucketNums[nBucketId]++;
		}

		int nLastMax = nMin;
		int nMaxGap = 0;
		for (int i = 0; i < nBucketCount; ++i)
		{
			if (vecBucketNums[i] == 0) continue;
			nMaxGap = max(nMaxGap, vecMin[i] - nLastMax);
			nLastMax = vecMax[i];
		}
		return nMaxGap;
	}

	static void test()
	{
		vector<int> v{ 1,1,1,1,1,1,1,1,1,2,3 };
		maximumGap(v);
	}
};
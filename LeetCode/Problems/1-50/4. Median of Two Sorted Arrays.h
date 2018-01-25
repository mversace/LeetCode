#pragma once
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution4 {
public:
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = (int)nums1.size();
		int n = (int)nums2.size();
		vector<int> vecMerge(m + n);
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), vecMerge.begin());
		sort(vecMerge.begin(), vecMerge.end());

		int nSize = m + n;

		if (nSize % 2 == 1)
			return double(vecMerge[nSize / 2]);
		else
			return double((vecMerge[(nSize - 1) / 2] + vecMerge[(nSize + 1) / 2]) / 2.0f);
	}

	static void test()
	{
		vector<int> nums1 = {1,2};
		vector<int> nums2 = {3,4};
		double a = findMedianSortedArrays(nums1, nums2);
		int n = 0;
	}
};
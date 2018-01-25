#pragma once
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vecRet;
		int nSize = (int)nums.size();
		for (int i = 0; i < nSize; ++i)
		{
			for (int j = i + 1; j < nSize; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					vecRet.push_back(i);
					vecRet.push_back(j);
					return vecRet;
				}
			}
		}

		return vecRet;
	}

	static void test()
	{
		vector<int> vecTemp = {0, 2, 4, 0};
		twoSum(vecTemp, 0);
	}
};
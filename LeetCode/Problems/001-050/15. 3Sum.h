#pragma once
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

#include <vector>
#include <map>
#include <algorithm>
using std::vector;
using std::map;

class Solution15 {
public:
	static vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vecOut;

		map<int, int> mapTemp;
		for (auto i : nums)
			++mapTemp[i];

		auto it = mapTemp.begin();
		for ( ;it != mapTemp.end(); ++it)
		{
			if (it->first > 0) break;
			if (it->first == 0)
			{
				if (it->second >= 3)
					vecOut.push_back(vector<int>{0, 0, 0});
			}
			else if (it->second >= 2 && mapTemp.find(-it->first * 2) != mapTemp.end())
			{
				vecOut.push_back(vector<int>{it->first, it->first, -it->first * 2});
			}
			
			auto it1 = it;
			++it1;
			for (; it1 != mapTemp.end(); ++it1)
			{
				if (it->first + it1->first > 0) break;
				if (it->first + it1->first * 2 == 0)
				{
					if (it1->second >= 2)
						vecOut.push_back(vector<int>{it->first, it1->first, it1->first});
				}
				else
				{
					auto itTemp = mapTemp.find(-it->first - it1->first);
					if (itTemp != mapTemp.end() && itTemp->first > it1->first)
						vecOut.push_back(vector<int>{it->first, it1->first, -it->first - it1->first});
				}
			}
		}

		return vecOut;
	}

	static void test()
	{
		vector<int> vec = {-1, 0, 1, 2, -1, -4};
		threeSum(vec);
	}
};
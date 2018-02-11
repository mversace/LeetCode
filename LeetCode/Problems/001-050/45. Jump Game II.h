#pragma once
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include <vector>
using std::vector;
class Solution45 {
public:
	static int jump(vector<int>& nums) {
		// BFS
		// one time loop. 
		// get current level range. and get next level range
		int nLen = (int)nums.size();
		int nMaxRange = 0;
		int nLevel = 0;
		int nCurrentMax = 0;
		for (int i = 0; i < nLen - 1; ++i)
		{
			nMaxRange = max(nMaxRange, i + nums[i]);
			if (i == nCurrentMax)
			{
				++nLevel;
				nCurrentMax = nMaxRange;
			}
		}
		
		return nLevel;
	}

	static void test()
	{
		jump(vector<int>{1,2,0,1});
	}
};
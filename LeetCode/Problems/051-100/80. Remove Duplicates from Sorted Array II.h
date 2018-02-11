#pragma once
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.


*/
#include <vector>
using std::vector;
class Solution80 {
public:
	static int removeDuplicates(vector<int>& nums) {
		int nLen = (int)nums.size();
		int l = 2, r = 2;
		while (l < nLen)
		{
			while (l < nLen && nums[l] >= nums[l - 1])
			{
				if (nums[l] == nums[l - 1] && nums[l] == nums[l - 1])
					break;

				++l;
				++r;
			}

			while (r < nLen)
			{
				if (nums[r] > nums[l - 1]) break;
				if (nums[r] == nums[l - 1] && nums[l - 1] != nums[l - 2]) break;
				++r;
			}

			if (l < nLen)
			{
				if (r < nLen)
				{
					swap(nums[l], nums[r]);
					++l;
				}
				else
				{
					break;
				}
			}
		}

		return min(l, nLen);
	}

	static void test()
	{
		removeDuplicates(vector<int>{1, 1, 1});
	}
};
#pragma once
/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/
#include <vector>
using std::vector;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> vec = digits;
		for (int i = (int)vec.size() - 1; i >= 0; --i)
		{
			if (vec[i] == 9)
				vec[i] = 0;
			else
			{
				vec[i]++;
				return vec;
			}
		}
		vec[0] = 1;
		vec.push_back(0);
		return vec;
	}
};
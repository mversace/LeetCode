#pragma once
/*
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution60 {
public:
	static string getPermutation(int n, int k) {
		string s;
		for (int i = 0; i < n; ++i)
			s.push_back('0' + i + 1);

		vector<int> vec(n, 1);
		for (int i = 1; i < n; ++i)
			vec[i] = i * vec[i - 1];

		reverse(vec.begin(), vec.end());

		string strResult;
		for (int i = 0; i < n; ++i)
		{
			int a = (k - 1) / vec[i];
			strResult.push_back(s[a]);
			s.erase(s.begin() + a);
			k -= vec[i] * a; 
		}

		return strResult;
	}

	static void test()
	{
		getPermutation(3,5);
	}
};
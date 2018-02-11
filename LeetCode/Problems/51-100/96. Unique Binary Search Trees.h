#pragma once
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3

*/
#include <vector>
using std::vector;
class Solution {
public:
	int numTrees(int n) {
		// 95. Unique Binary Search Trees II
		// dp[x]: 1-n有多少二叉树
		// 以x为例，root从1-x的所有结果相加。已1为root的树数量为:dp[1-1]*dp[x-1]
		// dp[x] = dp[1-1]*dp[x-1] + dp[2-1]*dp[x-2] + dp[3-1]*d[x-3]+...dp[n-1]*dp[x-n-1]

		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j) // 以j作为root节点
			{
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}
};
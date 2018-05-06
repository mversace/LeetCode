#pragma once
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include <vector>
using std::vector;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		// 对于任意vector,第一步精简为：{a, b, c, d, e}
		// 此时一定有 (b > a)
		// 利润 = (b - a) + {b, c, d, e},循环
		// 实际为: if (v[i + 1] > v[i]) profit += (v[i + 1] - v[i])
		int nProfit = 0;
		for (int i = 1; i < (int)prices.size(); ++i)
		{
			if (prices[i] > prices[i - 1])
				nProfit += (prices[i] - prices[i - 1]);
		}
		return nProfit;
	}
};
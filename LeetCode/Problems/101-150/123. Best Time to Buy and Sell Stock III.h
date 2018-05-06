#pragma once
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <vector>
#include <algorithm>
using std::vector;
class Solution123 {
public:
	static int maxProfit(vector<int>& prices) {
		// 两种可能。1次买卖就最大利润、需要两次买卖
		// 需要两次买卖的情况，一定是利润1大于买2，导致第二次买的时候成本<=0
		// 例如 1, 3, 3, 4 一次就够了，如果改为1324,则需要买卖两次
		int nOneBuyPrice = INT_MAX;
		int nOneSellProfit = 0;
		int nTwoBuyPrice = INT_MAX;
		int nTwoSellProfit = 0;
		for (auto i : prices)
		{
			nOneBuyPrice = min(nOneBuyPrice, i);
			nOneSellProfit = max(nOneSellProfit, i - nOneBuyPrice);
			// nOneSellProfit = 0 则nOneSellProfit == nTwoSellProfit
			// 如果利润1足够高，会把买2的成本价降到负数
			nTwoBuyPrice = min(nTwoBuyPrice, i - nOneSellProfit); 
			nTwoSellProfit = max(nTwoSellProfit, i - nTwoBuyPrice);
		}
		return nTwoSellProfit;
	}

	static void test()
	{
		vector<int> a{1, 2, 3};
		maxProfit(a);
	}
};
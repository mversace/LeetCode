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
		// ���ֿ��ܡ�1�����������������Ҫ��������
		// ��Ҫ���������������һ��������1������2�����µڶ������ʱ��ɱ�<=0
		// ���� 1, 3, 3, 4 һ�ξ͹��ˣ������Ϊ1324,����Ҫ��������
		int nOneBuyPrice = INT_MAX;
		int nOneSellProfit = 0;
		int nTwoBuyPrice = INT_MAX;
		int nTwoSellProfit = 0;
		for (auto i : prices)
		{
			nOneBuyPrice = min(nOneBuyPrice, i);
			nOneSellProfit = max(nOneSellProfit, i - nOneBuyPrice);
			// nOneSellProfit = 0 ��nOneSellProfit == nTwoSellProfit
			// �������1�㹻�ߣ������2�ĳɱ��۽�������
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
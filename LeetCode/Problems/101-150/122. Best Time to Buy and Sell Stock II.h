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
		// ��������vector,��һ������Ϊ��{a, b, c, d, e}
		// ��ʱһ���� (b > a)
		// ���� = (b - a) + {b, c, d, e},ѭ��
		// ʵ��Ϊ: if (v[i + 1] > v[i]) profit += (v[i + 1] - v[i])
		int nProfit = 0;
		for (int i = 1; i < (int)prices.size(); ++i)
		{
			if (prices[i] > prices[i - 1])
				nProfit += (prices[i] - prices[i - 1]);
		}
		return nProfit;
	}
};
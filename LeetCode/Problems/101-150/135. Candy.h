#pragma once
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/
#include <vector>
using std::vector;
class Solution135 {
public:
	static int candy(vector<int>& ratings) {
		// 从i遍历k，直到ratings[k+1] > ratings[k]，说明i-k之间已经分配好了糖果，给k+1分配‘k的+1’
		// 如果ratings[k+1] == ratings[k] ，说明i-k之间已经分配好了糖果，给k+1分配1
		// 如果ratings[k+1] < ratings[k]，给k+1分配1，并且给i-k的数值全部+1，重复
		int start = 0; // 此次判断的起始位置
		int candys = 0; // 糖果总数
		int leftCandy = 0; // 上一个位置的糖果
		int startCandy = 0; // 起始位置的糖果
		for (int i = 0; i < (int)ratings.size(); ++i)
		{
			if (i == 0)
			{
				leftCandy = 1;
				candys += leftCandy;
			}
			else
			{
				if (ratings[i] > ratings[i - 1])
				{
					start = i;
					leftCandy++;
					candys += leftCandy;
					startCandy = leftCandy;
				}
				else if (ratings[i] == ratings[i - 1])
				{
					start = i;
					leftCandy = 1;
					candys += leftCandy;
					startCandy = leftCandy;
				}
				else
				{
					candys += i - start;

					if (startCandy > 1)
					{
						--startCandy;
						--candys;
					}

					leftCandy = 1;
					candys += leftCandy;
				}
			}
		}
		return candys;
	}

	static void test()
	{
		vector<int> v{1,3,2,1 };
		candy(v);
	}
};
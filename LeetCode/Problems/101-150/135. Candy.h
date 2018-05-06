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
		// ��i����k��ֱ��ratings[k+1] > ratings[k]��˵��i-k֮���Ѿ���������ǹ�����k+1���䡮k��+1��
		// ���ratings[k+1] == ratings[k] ��˵��i-k֮���Ѿ���������ǹ�����k+1����1
		// ���ratings[k+1] < ratings[k]����k+1����1�����Ҹ�i-k����ֵȫ��+1���ظ�
		int start = 0; // �˴��жϵ���ʼλ��
		int candys = 0; // �ǹ�����
		int leftCandy = 0; // ��һ��λ�õ��ǹ�
		int startCandy = 0; // ��ʼλ�õ��ǹ�
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
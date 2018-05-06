#pragma once
/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input:
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/
#include <vector>
using std::vector;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// 1.从A开始一直走，直到遇见不能到达的B，此时AB之间的任意点都不可能到达B,起点需要从B开始继续寻找
		// 证明:假设A到B之间有一个点C，A能到C但不能到B，A到C时剩余gas>=0，此时都无法到B，那么从C(gas=0)也不能到B
		// 2.如果全程总gas数大于消耗数，必然会有一个站A，从A开始必然可以走完全程
		// 证明:从A开始，能达到的站设置为绿色，不能的设置为红色，同色合并
		//      最终结果必然是‘绿红绿红’交叉，因为总绿色大于总红色，开始临近的红绿合并。因为是循环一个圈，总能有一个绿>=红
		//      合并到最后会剩余一个绿色，所以必然存在一个站可以实现
		int tank = 0;
		int totalCost = 0, totalTank = 0;
		int start = 0;
		for (int i = 0; i < (int)gas.size(); ++i)
		{
			totalTank += gas[i];
			totalCost += cost[i];
			tank += gas[i] - cost[i];
			if (tank < 0)
			{
				start = i + 1;
				tank = 0;
			}
		}
		return totalTank >= totalCost ? start : -1;
	}
};
#pragma once
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
#include <vector>
#include <stack>
#include <string>
using std::vector;
using std::stack;
using std::string;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> q;
		for (auto i : tokens)
		{
			if (i.empty()) continue;
			if (i == "+" || i == "-" || i == "*" || i == "/")
			{
				if (q.size() < 2)
					continue;

				int b = q.top();
				q.pop();
				int a = q.top();
				q.pop();

				char c = i[0];
				switch (c)
				{
				case '+': q.push(a + b); break;
				case '-': q.push(a - b); break;
				case '*': q.push(a * b); break;
				case '/': q.push(a / b); break;
				default: break;
				}
			}
			else
			{
				q.push(atoi(i.c_str()));
			}
		}
		return q.top();
	}
};
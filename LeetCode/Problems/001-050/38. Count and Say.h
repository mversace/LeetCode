#pragma once
/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "121
*/
#include <string>
#include <queue>
using std::string;
using std::queue;

class Solution {
public:
	string countAndSay(int n) {
		queue<char> s;
		while (n--)
		{
			if (s.empty())
				s.push('1');
			else
			{
				queue<char> sTemp;
				char c = 0;
				int n = 0;
				while (!s.empty())
				{
					if (s.front() != c)
					{
						if (n > 0)
						{
							sTemp.push('0' + n);
							sTemp.push(c);
						}
						c = s.front();
						n = 1;
					}
					else
					{
						++n;
					}
					s.pop();
				}
				if (n > 0)
				{
					sTemp.push('0' + n);
					sTemp.push(c);
				}
				s = sTemp;
			}
		}
		string sResult;
		while (!s.empty())
		{
			sResult.push_back(s.front());
			s.pop();
		}
		return sResult;
	}
};
#pragma once
/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/
#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	bool TryPutDownQueen(int& nResult, int n, int nStart, unordered_map<int, int>& mapTemp)
	{
		if (nStart == n)
		{
			++nResult;
			return true;
		}

		for (int i = 0; i < n; ++i)
		{
			bool bValid = true;
			for (auto m : mapTemp)
			{
				if (m.second == i || abs(nStart - m.first) == abs(i - m.second))
				{
					bValid = false;
					break;
				}
			}
			if (!bValid) continue;

			mapTemp[nStart] = i;
			TryPutDownQueen(nResult, n, nStart + 1, mapTemp);
			mapTemp.erase(nStart);
		}
		return false;
	}

	int totalNQueens(int n) {
		int nResult = 0;
		unordered_map<int, int> mapTemp;
		TryPutDownQueen(nResult, n, 0, mapTemp);

		return nResult;
	}
};
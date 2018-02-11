#pragma once
/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*/
#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class Solution51 {
public:
	static bool TryPutDownQueen(vector<vector<string>>& vec, int n, int nStart, unordered_map<int,int>& mapTemp)
	{
		if (nStart == n)
		{
			vector<string> vecSolution(n, string(n, '.'));
			for (auto m : mapTemp)
				vecSolution[m.first][m.second] = 'Q';
			vec.push_back(vecSolution);
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
			TryPutDownQueen(vec, n, nStart + 1, mapTemp);
			mapTemp.erase(nStart);
		}
		return false;
	}

	static vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> vec;
		unordered_map<int, int> mapTemp;
		TryPutDownQueen(vec, n, 0, mapTemp);

		return vec;
	}

	static void test()
	{
		solveNQueens(4);
	}
};
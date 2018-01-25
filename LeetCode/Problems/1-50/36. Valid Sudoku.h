#pragma once
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

*/

#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int nH = (int)board.size();
		if (nH != 9)
			return false;
		
		// ≈–∂œ∫·œÚ
		for (int y = 0; y < 9; ++y)
		{
			int nW = (int)board[y].size();
			if (nW != 9)
				return false;

			map<char, bool> mapTempRow;
			map<char, bool> mapTempCol;
			map<char, bool> mapTemp9;
			for (int x = 0; x < 9; ++x)
			{
				// ∫·œÚ
				char c = board[y][x];
				if (c != '.')
				{
					if (mapTempRow.find(c) != mapTempRow.end())
						return false;
					mapTempRow[c] = true;
				}

				// ◊›œÚ
				c = board[x][y];
				if (c != '.')
				{
					if (mapTempCol.find(c) != mapTempCol.end())
						return false;
					mapTempCol[c] = true;
				}

				// æ≈π¨∏Ò
				int nXPos = (y % 3) * 3 + x % 3;
				int nYPos = (y / 3) * 3 + x / 3;
				c = board[nXPos][nYPos];
				if (c != '.')
				{
					if (mapTemp9.find(c) != mapTemp9.end())
						return false;
					mapTemp9[c] = true;
				}
			}
		}
		return true;
	}
};
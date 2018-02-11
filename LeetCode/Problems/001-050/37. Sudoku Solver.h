#pragma once
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
#include <vector>
using std::vector;

class Solution {
public:
	bool Check(vector<vector<char>>& board, int row, int col, char c)
	{
		for (int i = 0; i < 9; ++i)
		{
			// ÐÐ
			if (board[row][i] == c)
				return false;
			// ÁÐ
			if (board[i][col] == c)
				return false;

			// ¾Å¹¬¸ñ
			int nRow = row / 3 * 3 + i / 3;
			int nCol = col / 3 * 3 + i % 3;
			if (board[nRow][nCol] == c)
				return false;
		}
		return true;
	}

	bool TrySolve(vector<vector<char>>& board, int row, int col)
	{
		if (row == 9)
			return true;

		if (col == 9)
			return TrySolve(board, row + 1, 0);

		if (board[row][col] != '.')
			return TrySolve(board, row, col + 1);

		for (char c = '1'; c <= '9'; ++c)
		{
			if (Check(board, row, col, c))
			{
				board[row][col] = c;
				if (TrySolve(board, row, col + 1))
					return true;
				board[row][col] = '.';
			}
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		TrySolve(board, 0, 0);
	}
};
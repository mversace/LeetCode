#pragma once
/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn¡¯t be on the border, 
which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
#include <vector>
using std::vector;
class Solution130 {
public:
	static void DFS(vector<vector<char>>& board, int nRow, int nCol)
	{
		board[nRow][nCol] = '1';

		// left
		if (nCol > 0 && board[nRow][nCol - 1] == 'O') DFS(board, nRow, nCol - 1);
		// top
		if (nRow > 0 && board[nRow - 1][nCol] == 'O') DFS(board, nRow - 1, nCol);
		// right
		if (nCol < (int)board[nRow].size() - 1 && board[nRow][nCol + 1] == 'O') DFS(board, nRow, nCol + 1);
		// bottom
		if (nRow < (int)board.size() - 1 && board[nRow + 1][nCol] == 'O') DFS(board, nRow + 1, nCol);
	}
	static void solve(vector<vector<char>>& board) {
		// DFS
		// top && bottom row
		int nRowCount = (int)board.size();
		if (nRowCount <= 0) return;
		int nColCount = (int)board[0].size();
		for (int i = 0; i < nColCount; ++i)
		{
			if (board[0][i] == 'O') DFS(board, 0, i);
			if (board[nRowCount - 1][i] == 'O') DFS(board, nRowCount - 1, i);
		}
		// left && right col
		for (int i = 0; i < nRowCount; ++i)
		{
			if (board[i][0] == 'O') DFS(board, i, 0);
			if (board[i][nColCount - 1] == 'O') DFS(board, i, nColCount - 1);
		}

		for (auto &i : board)
		{
			for (auto &j : i)
			{
				j = (j == '1') ? 'O' : 'X';
			}
		}
	}

	static void test()
	{
		vector<vector<char>> v{ {'X', 'O', 'X', 'O', 'X', 'O'},{'O', 'X', 'O', 'X', 'O', 'X'},{'X', 'O', 'X', 'O', 'X', 'O'},{'O', 'X', 'O', 'X', 'O', 'X'
	}
};
		solve(v);
		int n = 1;
	}
};
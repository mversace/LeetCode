#pragma once
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution79 {
public:
	static bool CheckExist(vector<vector<char>>& board, int r, int c, string word, int l)
	{
		int nSize = (int)word.size();
		if (l == nSize)
			return true;
		int m = (int)board.size();
		int n = (int)board[0].size();
		char ct = board[r][c];
		board[r][c] = 0;

		// four dir
		if (c > 0 && board[r][c - 1] == word[l] && CheckExist(board, r, c - 1, word, l + 1))
			return true;
		if (r > 0 && board[r - 1][c] == word[l] && CheckExist(board, r - 1, c, word, l + 1))
			return true;
		if (c + 1 < n && board[r][c + 1] == word[l] && CheckExist(board, r, c + 1, word, l + 1))
			return true;
		if (r + 1 < m && board[r + 1][c] == word[l] && CheckExist(board, r + 1, c, word, l + 1))
			return true;
		
		board[r][c] = ct;
		return false;
	}

	static bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		int r = (int)board.size();
		if (r == 0) return false;
		int c = (int)board[0].size();
		if (c == 0) return false;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (board[i][j] == word[0])
				{
					if (CheckExist(board, i, j, word, 1))
						return true;
				}
			}
		}
		return false;
	}

	static void test()
	{
		exist(vector<vector<char>>{ {'A'}}, "AB");
	}
};
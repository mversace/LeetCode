#pragma once
/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using std::string;
using std::vector;
using std::unordered_set;
using std::queue;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordSet(wordList.begin(), wordList.end());
		queue<vector<string>> bfs;
		bfs.push({ beginWord });
		vector<string> visited;

		// fuck u
		if (0 == wordSet.count(endWord))
			return 0;

		while (!bfs.empty())
		{
			size_t n = bfs.size();
			for (size_t i = 0; i < n; ++i)
			{
				auto vs = bfs.front();
				bfs.pop();
				auto s = vs.back();
				for (auto &c : s)
				{
					auto cT = c;
					for (c = 'a'; c < 'z'; ++c)
					{
						if (0 == wordSet.count(s)) continue;
						auto path = vs;
						path.push_back(s);
						visited.push_back(s);
						if (s == endWord) return (int)path.size();
						else bfs.push(path);
					}
					c = cT;
				}
			}

			for (auto s : visited) wordSet.erase(s);
			visited.clear();
		}

		return 0;
	}
};
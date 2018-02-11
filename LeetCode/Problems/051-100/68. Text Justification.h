#pragma once
/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution68 {
public:
	static string FormatString(const vector<string>& words, int maxWidth, int nTotalLen)
	{
		string s;
		int nCount = (int)words.size();
		if (nCount == 1)
		{
			s = words[0];
			for (int i = 0; i < maxWidth - nTotalLen; ++i)
				s.push_back(' ');
		}
		else
		{
			int nSpace = (maxWidth - nTotalLen) / (nCount - 1);
			int nSpaceEx = maxWidth - nTotalLen - nSpace * (nCount - 1);
			for (int kk = 0; kk < nCount; ++kk)
			{
				s += words[kk];
				if (kk == nCount - 1) break;

				for (int mm = 0; mm < nSpace; ++mm)
					s.push_back(' ');
				if (kk < nSpaceEx)
					s.push_back(' ');
			}
		}
		return s;
	}

	static vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> vec;
		vector<string> vecTemp;
		int nTotalLen = 0;
		int nLen = (int)words.size();
		for (int i = 0; i <= nLen; ++i)
		{
			int nWordCount = (int)vecTemp.size();
			if (i == nLen || nTotalLen + nWordCount + (int)words[i].size() > maxWidth)
			{
				string s;
				if (i == nLen)
				{
					for (int kk = 0; kk < nWordCount; ++kk)
					{
						s += vecTemp[kk];
						if (kk != nWordCount - 1)
							s.push_back(' ');
					}
					int n = (int)s.length();
					for (int kk = 0; kk < maxWidth - n; ++kk)
						s.push_back(' ');
				}
				else
				{
					s = FormatString(vecTemp, maxWidth, nTotalLen);
				}

				vec.push_back(s);
				vecTemp.clear();
				if (i != nLen)
				{
					vecTemp.push_back(words[i]);
					nTotalLen = (int)words[i].length();
				}
			}
			else
			{
				nTotalLen += (int)words[i].length();
				vecTemp.push_back(words[i]);
			}
		}

		return vec;
	}

	static void test()
	{
		fullJustify(vector<string>{"a", "b", "c", "d", "e"}, 3);
	}
};
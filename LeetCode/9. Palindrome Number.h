#pragma once
/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

/*
Do this without extra space? fuck u
*/

class Solution9 {
public:
	static bool isPalindrome(int x) {
		if (x < 0) return false;
		int fuck = x, fuckTemp = 0;
		while (fuck)
		{
			fuckTemp = fuckTemp * 10 + fuck % 10;
			fuck /= 10;
		}
		return x == fuckTemp;
	}

	static void test()
	{
		isPalindrome(123321);
	}
};
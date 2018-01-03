#pragma once

/*
ÂÝÐý¾ØÕó
 1  2  3
 8  9  4
 7	6  5
*/

#include <memory>
#include <iostream>

using namespace std;
void LuoXuanFunc(int n)
{
	if (n <= 0)
		return;

	int* pData = new int[n * n];
	memset(pData, 0, n * n * sizeof(int));

	int nDir = 0; // 0¡ú 1¡ý 2¡û 3¡ü

	int nX = 0;
	int nY = 0;
	for (int i = 1; i < n * n + 1; ++i)
	{
		int nIdx = nY * n + nX;

		if (nX >= n || nY >= n || nX < 0 || nY < 0 || nIdx > n * n || pData[nIdx] != 0)
		{
			switch (nDir)
			{
			case 0: --nX; ++nY; break;
			case 1: --nY; --nX; break;
			case 2: ++nX; --nY; break;
			case 3: ++nY; ++nX; break;
			}
			nDir = (nDir + 1) % 4;
		}
		
		pData[nY * n + nX] = i;
		switch (nDir)
		{
		case 0: ++nX; break;
		case 1: ++nY; break;
		case 2: --nX; break;
		case 3: --nY; break;
		}
		
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%3d ", pData[i * n + j]);
		printf("\n");
	}
}
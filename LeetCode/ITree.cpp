#include "ITree.h"
#include <stack>
#include <queue>
#include <iostream>

ITree::ITree()
{
	m_pHead = nullptr;
}

ITree::~ITree()
{
	for (auto i : m_mapNodes)
		delete i.first;
	m_mapNodes.clear();
	m_pHead = nullptr;
}

void ITree::AddNode(int nValue)
{
	tTreeData* pData = AddNodeChild(nValue);

	if (pData)
		m_mapNodes[pData] = true;
}

void ITree::DelNode(int nValue)
{
	tTreeData* pData = DelNodeChild(nValue);

	if (pData)
	{
		delete pData;
		m_mapNodes.erase(pData);
	}
}

void ITree::TestTraverse()
{
	std::vector<int> vecTest;
	for (int i = 0; i < 20; ++i)
		vecTest.push_back(i);
	std::random_shuffle(vecTest.begin(), vecTest.end());

	for (auto i : vecTest)
		AddNode(i);

	std::vector<int> vecResult;

	vecResult.clear();
	vecResult = TraverseFront();
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;

	vecResult.clear();
	TraverseFrontEx(m_pHead, &vecResult);
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;

	vecResult.clear();
	vecResult = TraverseMiddle();
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;

	vecResult.clear();
	TraverseMiddleEx(m_pHead, &vecResult);
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;

	vecResult.clear();
	vecResult = TraverseBack();
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;

	vecResult.clear();
	TraverseBackEx(m_pHead, &vecResult);
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;

	vecResult.clear();
	vecResult = TraverseLevel();
	for (auto i : vecResult)
		std::cout << i << " ";
	std::cout << std::endl;
}

tTreeData* ITree::GetHead()
{
	return m_pHead;
}

std::vector<int> ITree::TraverseFront()
{
	// 先序遍历 根->左->右
	std::vector<int> vecResult;

	tTreeData* pTemp = m_pHead;
	std::stack<tTreeData*> sTemp;
	while (!sTemp.empty() || pTemp)
	{
		while (pTemp)
		{
			vecResult.push_back(pTemp->nValue);
			sTemp.push(pTemp);
			pTemp = pTemp->pLeft;
		}

		if (!sTemp.empty())
		{
			pTemp = sTemp.top();
			sTemp.pop();
			pTemp = pTemp->pRight;
		}
	}

	return vecResult;
}

void ITree::TraverseFrontEx(tTreeData* pNode, std::vector<int>* pVec)
{
	// 先序遍历 根->左->右
	if (pNode)
	{
		if (pVec)
			pVec->push_back(pNode->nValue);

		TraverseFrontEx(pNode->pLeft, pVec);
		TraverseFrontEx(pNode->pRight, pVec);
	}
}

std::vector<int> ITree::TraverseMiddle()
{
	// 中序遍历 左->根->右
	std::vector<int> vecResult;

	tTreeData* pTemp = m_pHead;
	std::stack<tTreeData*> sTemp;
	while (!sTemp.empty() || pTemp)
	{
		while (pTemp)
		{
			sTemp.push(pTemp);
			pTemp = pTemp->pLeft;
		}

		if (!sTemp.empty())
		{
			pTemp = sTemp.top();
			sTemp.pop();
			vecResult.push_back(pTemp->nValue);
			pTemp = pTemp->pRight;
		}
	}

	return vecResult;
}

void ITree::TraverseMiddleEx(tTreeData* pNode, std::vector<int>* pVec)
{
	if (pNode)
	{
		TraverseMiddleEx(pNode->pLeft, pVec);

		if (pVec)
			pVec->push_back(pNode->nValue);

		TraverseMiddleEx(pNode->pRight, pVec);
	}
}

std::vector<int> ITree::TraverseBack()
{
	// 后序遍历 左->右->根
	std::vector<int> vecResult;

	if (!m_pHead)
		return vecResult;

	tTreeData* pTemp = nullptr;
	tTreeData* pLast = nullptr;
	std::stack<tTreeData*> sTemp;

	sTemp.push(m_pHead);
	while (!sTemp.empty())
	{
		pTemp = sTemp.top();
		if ((!pTemp->pLeft && !pTemp->pRight)
			|| (pLast && (pTemp->pLeft == pLast || pTemp->pRight == pLast)))
		{
			vecResult.push_back(pTemp->nValue);
			sTemp.pop();
			pLast = pTemp;
		}
		else
		{
			if (pTemp->pRight)
				sTemp.push(pTemp->pRight);
			if (pTemp->pLeft)
				sTemp.push(pTemp->pLeft);
		}
	}

	return vecResult;
}

void ITree::TraverseBackEx(tTreeData* pNode, std::vector<int>* pVec)
{
	if (pNode)
	{
		TraverseBackEx(pNode->pLeft, pVec);
		TraverseBackEx(pNode->pRight, pVec);

		if (pVec)
			pVec->push_back(pNode->nValue);
	}
}

std::vector<int> ITree::TraverseLevel()
{
	// 层序遍历 一层一层查
	std::vector<int> vecResult;

	tTreeData* pTemp = m_pHead;
	std::queue<tTreeData*> sTemp;

	if (pTemp)
		sTemp.push(pTemp);

	while (!sTemp.empty())
	{
		pTemp = sTemp.front();
		sTemp.pop();
		vecResult.push_back(pTemp->nValue);

		if (pTemp->pLeft)
			sTemp.push(pTemp->pLeft);
		if (pTemp->pRight)
			sTemp.push(pTemp->pRight);
	}

	return vecResult;
}
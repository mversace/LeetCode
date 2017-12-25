#pragma once
/*
	普通二叉树
	链表结构，插入规则为小的在左边，大的右边
*/

#include "ITree.h"

class CBinaryTree : public ITree
{
protected:
	virtual tTreeData* AddNodeChild(int nValue) override;
	virtual tTreeData* DelNodeChild(int nValue) override;
};

tTreeData* CBinaryTree::AddNodeChild(int nValue)
{
	if (!m_pHead)
	{
		m_pHead = new tTreeData(nValue);
		return m_pHead;
	}

	tTreeData* pTemp = m_pHead;
	tTreeData* pFather = nullptr;
	while (pTemp)
	{
		if (pTemp->nValue == nValue)
			return nullptr;

		pFather = pTemp;
		if (nValue < pTemp->nValue)
			pTemp = pTemp->pLeft;
		else
			pTemp = pTemp->pRight;
	}

	tTreeData* pNew = new tTreeData(nValue);
	pNew->pFather = pFather;
	if (pFather->nValue > nValue)
		pFather->pLeft = pNew;
	else
		pFather->pRight = pNew;

	return pNew;
}

tTreeData* CBinaryTree::DelNodeChild(int nValue)
{
	// will
	return nullptr;
}
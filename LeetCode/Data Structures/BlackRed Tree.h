#pragma once
/*
	红黑树
	通过左旋，右旋达到相对平衡的二叉树结构
*/
#include "ITree.h"

class CBlackRedTree : public ITree
{
public:
	virtual tTreeData* AddNodeChild(int nValue) override;
	virtual tTreeData* DelNodeChild(int nValue) override;

private:
	void FixTheTree(tTreeData* pNode);
	void LeftRotate(tTreeData* pNode);
	void RightRotate(tTreeData* pNode);
};

tTreeData* CBlackRedTree::AddNodeChild(int nValue)
{
	if (!m_pHead)
	{
		m_pHead = new tTreeData(nValue);
		m_pHead->bColor = COLOR_BLACK;
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

	FixTheTree(pNew);

	return pNew;
}

tTreeData* CBlackRedTree::DelNodeChild(int nValue)
{
	return nullptr;
}

void CBlackRedTree::FixTheTree(tTreeData* pNode)
{
	tTreeData* pFather = pNode->pFather;

	// 父节点为红色，必然不平衡
	// 因为根节点为黑，所以父节点也不会是根节点
	while (pFather && pFather->bColor == COLOR_RED)
	{
		tTreeData* pGrandFather = pFather->pFather;

		if (pFather == pGrandFather->pLeft)
		{
			tTreeData* pUncle = pGrandFather->pRight;
			if (pUncle && pUncle->bColor == COLOR_RED)
			{
				// 父亲、叔叔、爷爷3节点换色
				pFather->bColor = COLOR_BLACK;
				pUncle->bColor = COLOR_BLACK;
				pGrandFather->bColor = COLOR_RED;
				pFather = pGrandFather->pFather;
				continue;
			}
		}
		else
		{

		}
	}
}
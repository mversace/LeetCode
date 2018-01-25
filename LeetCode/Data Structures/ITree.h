#pragma once

#include <map>
#include <vector>

#define COLOR_BLACK (0)
#define COLOR_RED	(1)
struct tTreeData 
{
	int nValue;
	unsigned char bColor; 

	tTreeData* pFather;
	tTreeData* pLeft;
	tTreeData* pRight;

	tTreeData(int n)
	{
		nValue = n;
		pFather = nullptr;
		pLeft = nullptr;
		pRight = nullptr;
		bColor = COLOR_RED;
	}
};

class ITree
{
public:
	ITree();
	virtual ~ITree();

public:
	// 基类负责统一管理内存
	virtual void AddNode(int nValue) final;
	virtual void DelNode(int nValue) final;

public:
	void TestTraverse();

private:
	tTreeData* GetHead();
	std::vector<int> TraverseFront();	// 先序遍历 根->左->右
	void TraverseFrontEx(tTreeData* pNode, std::vector<int>* pVec); // 先序递归
	std::vector<int> TraverseMiddle();	// 中序遍历 左->根->右
	void TraverseMiddleEx(tTreeData* pNode, std::vector<int>* pVec); // 中序递归
	std::vector<int> TraverseBack();	// 后序遍历 左->右->根
	void TraverseBackEx(tTreeData* pNode, std::vector<int>* pVec); // 后序递归
	std::vector<int> TraverseLevel();	// 层序遍历 一层一层查

protected:
	virtual tTreeData* AddNodeChild(int nValue) = 0;
	virtual tTreeData* DelNodeChild(int nValue) = 0;

protected:
	tTreeData* m_pHead;

private:
	std::map<tTreeData*, bool> m_mapNodes;
};
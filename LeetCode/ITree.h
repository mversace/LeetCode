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
	// ���ฺ��ͳһ�����ڴ�
	virtual void AddNode(int nValue) final;
	virtual void DelNode(int nValue) final;

public:
	void TestTraverse();

private:
	tTreeData* GetHead();
	std::vector<int> TraverseFront();	// ������� ��->��->��
	void TraverseFrontEx(tTreeData* pNode, std::vector<int>* pVec); // ����ݹ�
	std::vector<int> TraverseMiddle();	// ������� ��->��->��
	void TraverseMiddleEx(tTreeData* pNode, std::vector<int>* pVec); // ����ݹ�
	std::vector<int> TraverseBack();	// ������� ��->��->��
	void TraverseBackEx(tTreeData* pNode, std::vector<int>* pVec); // ����ݹ�
	std::vector<int> TraverseLevel();	// ������� һ��һ���

protected:
	virtual tTreeData* AddNodeChild(int nValue) = 0;
	virtual tTreeData* DelNodeChild(int nValue) = 0;

protected:
	tTreeData* m_pHead;

private:
	std::map<tTreeData*, bool> m_mapNodes;
};
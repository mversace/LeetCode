#pragma once
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution23 {
private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
public:
	static ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* pResult = nullptr;
		map<int, ListNode*> mapTemp;

		// ×ª»¯³Émap
		for (auto i : lists)
		{
			if (!i) continue;

			ListNode* pTemp = i;
			ListNode* pNextTemp = nullptr;
			while (pTemp)
			{
				pNextTemp = pTemp->next;
				pTemp->next = mapTemp[pTemp->val];
				mapTemp[pTemp->val] = pTemp;
				pTemp = pNextTemp;
			}
		}

		ListNode* pNode = nullptr;
		for (auto i : mapTemp)
		{
			if (!pResult)
			{
				pResult = i.second;
				pNode = pResult;
			}
			else
			{
				pNode->next = i.second;
			}
			
			while (pNode->next) pNode = pNode->next;
		}

		return pResult;
	}

	static void test()
	{
		ListNode a(0);
		ListNode b(2);
		ListNode c(5);
		a.next = &b;
		b.next = &c;
		vector<ListNode*> vec = {&a};
		mergeKLists(vec);
	}
};
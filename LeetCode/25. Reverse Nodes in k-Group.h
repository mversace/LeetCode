#pragma once
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

class Solution25 {
private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
public:
	static ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1) return head;

		ListNode* pResult = nullptr;
		ListNode* pNode = nullptr;
		ListNode* pItemHead = head;
		ListNode* pItemTail = nullptr;

		// 反转k个Node
		while (pItemHead)
		{
			pItemTail = pItemHead;
			bool bEnough = true;
			for (int i = 0; i < k - 1; ++i)
			{
				if (pItemTail->next)
				{
					pItemTail = pItemTail->next;
				}
				else
				{
					bEnough = false;
					break;
				}
				
			}

			// 反转，pItemHead为新头，pItemTail为新尾部
			if (bEnough)
			{
				ListNode* pPre = pItemHead;
				ListNode* pNext = pItemHead->next;
				pItemHead->next = pItemTail->next;
				while (pPre != pItemTail)
				{
					/*
						a→b→c pPre = a pNext = b
					 to a←b c pPre = b pNext = c
					*/
					ListNode* pData = pNext;
					pNext = pNext->next;
					pData->next = pPre;
					pPre = pData;
				}
				ListNode* pTemp = pItemTail;
				pItemTail = pItemHead;
				pItemHead = pTemp;
			}

			// 接node
			if (!pResult)
			{
				pResult = pItemHead;
			}
			else
			{
				pNode->next = pItemHead;
			}

			// 给pNode赋值，移动pItemHead
			pNode = pItemTail;
			pItemHead = pItemTail->next;
		}

		return pResult;
	}

	static void test()
	{
		ListNode a(1);
		ListNode b(2);
		ListNode c(3);
		a.next = &b;
		b.next = &c;
		reverseKGroup(&a, 2);
	}
};
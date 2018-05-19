#pragma once
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

class Solution142 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	static ListNode *detectCycle(ListNode *head) {
		// A每次走1步，B每次都2步，AB相遇时A走了n步，容易得出cycle长度为2n-n=n
		ListNode* pOne = head;
		ListNode* pTwo = head;
		int n = 0;
		bool bHasCycle = false;
		while (pOne && pTwo && pTwo->next)
		{
			++n;
			pOne = pOne->next;
			pTwo = pTwo->next->next;
			if (pOne == pTwo)
			{
				bHasCycle = true;
				break;
			}
		}

		if (!bHasCycle) return nullptr;
		pOne = head;
		pTwo = head;
		while (n--) pTwo = pTwo->next;
		while (pOne != pTwo)
		{
			pOne = pOne->next;
			pTwo = pTwo->next;
		}
		return pOne;
	}

	static void test()
	{
		ListNode a(1);
		ListNode b(2);
		ListNode c(3);
		ListNode d(4);
		ListNode e(5);
		a.next = &b;
		b.next = &c;
		c.next = &d;
		d.next = &e;
		e.next = &b;
		detectCycle(&a);
	}
};
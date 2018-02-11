#pragma once
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

class Solution86 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	static ListNode* partition(ListNode* head, int x) {
		ListNode* p = head;
		ListNode* pt = nullptr; // 插入pt节点后，null代表插入链头

		// 先找到目标node
		while (p && p->val < x)
		{
			pt = p;
			p = p->next;
		}
			
		if (!p) return head;
		
		ListNode* pF = p;
		while (p)
		{
			if (p->val >= x)
			{
				pF = p;
				p = p->next;
			}
			else
			{
				// 取出p
				pF->next = p->next;
				// 插入pt后
				if (!pt)
				{
					p->next = head;
					head = p;
					pt = head;
				}
				else
				{
					p->next = pt->next;
					pt->next = p;
					pt = p;
				}
				p = pF->next;
			}
		}
		return head;
	}

	static void test()
	{
		ListNode a(2);
		ListNode b(1);
		a.next = &b;
		partition(&a, 2);
	}
};
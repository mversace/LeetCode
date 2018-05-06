#pragma once
/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
		1
	  /  \
	 2    3
	/ \    \
   4   5    7
After calling your function, the tree should look like:
		1 -> NULL
	  /  \
	 2 -> 3 -> NULL
	/ \    \
   4-> 5 -> 7 -> NULL
*/

class Solution117 {
public:
	struct TreeLinkNode {
		int val;
		TreeLinkNode *left, *right, *next;
		TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
	};

	static void connect(TreeLinkNode *root) {
		while (root)
		{
			TreeLinkNode* pNode = root;
			TreeLinkNode *pL = nullptr, *pLI = nullptr;
			while (pNode)
			{
				if (!pL)
				{
					pL = pNode->left;
					if (!pL)
						pL = pNode->right;

					if (pL) pLI = pL;
				}

				if (pNode->left)
					pNode->left->next = pNode->right;

				TreeLinkNode* pT = pNode->right ? pNode->right : pNode->left;
				if (pT) pLI = pT;

				if (pNode->next && pLI)
				{
					TreeLinkNode* pTT = pNode->next->left ? pNode->next->left : pNode->next->right;
					pLI->next = pTT;
					if (pTT) pLI = pTT;
				}
				pNode = pNode->next;
			}
			root = pL;
		}
	}

	static void test()
	{
		TreeLinkNode a(3);
		TreeLinkNode b(9);
		TreeLinkNode c(20);
		TreeLinkNode d(15);
		TreeLinkNode e(7);

		a.left = &b;
		a.right = &c;
		c.left = &d;
		c.right = &e;
		connect(&a);
	}
};
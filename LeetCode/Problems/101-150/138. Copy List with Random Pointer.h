#pragma once
/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
#include <unordered_map>
using std::unordered_map;
class Solution {
public:
	struct RandomListNode {
		int label;
		RandomListNode *next, *random;
		RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
	};

	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return nullptr;
		if (mp.find(head) == mp.end())
		{
			mp[head] = new RandomListNode(head->label);
			mp[head]->next = copyRandomList(head->next);
			mp[head]->random = copyRandomList(head->random);
		}
		return mp[head];
	}

private:
	unordered_map<RandomListNode*, RandomListNode*> mp;
};
#pragma once
/*
lone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

	1
   / \
  /   \
 0 --- 2
      / \
      \_/

*/
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
public:
	struct UndirectedGraphNode {
		int label;
		vector<UndirectedGraphNode *> neighbors;
		UndirectedGraphNode(int x) : label(x) {};
	};

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return nullptr;
		if (mp.find(node) == mp.end())
		{
			mp[node] = new UndirectedGraphNode(node->label);
			for (auto i : node->neighbors)
			{
				mp[node]->neighbors.push_back(cloneGraph(i));
			}
		}
		return mp[node];
	}

private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};
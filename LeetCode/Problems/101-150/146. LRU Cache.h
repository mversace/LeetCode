#pragma once
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
#include <unordered_map>
#include <list>
class LRUCache {
public:
	LRUCache(int capacity) : m_capacity(capacity) {
	}

	int get(int key) {
		auto it = m_hashMap.find(key);
		if (it == m_hashMap.end())
			return -1;

		m_list.splice(m_list.begin(), m_list, it->second);

		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m_hashMap.find(key);
		if (it != m_hashMap.end())
		{
			m_list.splice(m_list.begin(), m_list, it->second);
			it->second->second = value;
			return;
		}

		if (m_hashMap.size() == m_capacity)
		{
			m_hashMap.erase(m_list.back().first);
			m_list.pop_back();
		}

		m_list.emplace_front(key, value);
		m_hashMap[key] = m_list.begin();
	}

private:
	std::list<std::pair<int, int>> m_list;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_hashMap;
	size_t m_capacity;
};
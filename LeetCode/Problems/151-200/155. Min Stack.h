#pragma once
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
#include <vector>
using std::vector;
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		m_nIdx = 0;
	}

	void push(int x) {
		if (m_nIdx >= m_vec.size())
		{
			m_vec.push_back(x);
			m_vecMin.push_back(x);
		}
		else
		{
			m_vec[m_nIdx] = x;
			m_vecMin[m_nIdx] = x;
		}

		if (m_nIdx > 0)
			m_vecMin[m_nIdx] = min(x, m_vecMin[m_nIdx - 1]);

		++m_nIdx;
	}

	void pop() {
		--m_nIdx;
		m_nIdx = max(0, m_nIdx);
	}

	int top() {
		if (m_nIdx > 0)
			return m_vec[m_nIdx - 1];
		return -1;
	}

	int getMin() {
		if (m_nIdx > 0)
			return m_vecMin[m_nIdx - 1];
		return -1;
	}
private:
	vector<int> m_vec;
	vector<int> m_vecMin;
	int m_nIdx;
};

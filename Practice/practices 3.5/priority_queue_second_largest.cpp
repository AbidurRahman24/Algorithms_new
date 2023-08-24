#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Given vector
	vector<int> v{ 12, 35, 1, 10, 34, 1 };
	// Made a priority queue
	priority_queue<int> pq;
	// inserting all the element form vector v to priority
	// queue pq.
	for (int i = 0; i < v.size(); i++) {
		pq.push(v[i]);
	}

	// Remove largest element from pq
	pq.pop();

	// Now top of priority queue is second largest element
	cout << "The Second Largest Element in Vector is: ";
	cout << pq.top() << endl;

	return 0;
}

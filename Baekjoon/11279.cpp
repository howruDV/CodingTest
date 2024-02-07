// https://www.acmicpc.net/problem/11279
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> operations;
priority_queue<int> heap;

void solution()
{
	for (int& it : operations)
	{
		if (it == 0)
		{
			if (heap.empty())
				cout << 0 << "\n";
			else
			{
				cout << heap.top() << "\n";
				heap.pop();
			}
		}
		else
		{
			heap.push(it);
		}
	}
}

int main()
{
	// enhance iostream speed
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input
	int N;
	cin >> N;
	operations.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> operations[i];
	
	// solution
	solution();
	
	return 0;
}
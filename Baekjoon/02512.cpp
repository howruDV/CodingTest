// https://www.acmicpc.net/problem/2512
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> budget;

int IsPossible(int threshold)
{
	int total = 0;

	for (int& it : budget)
	{
		total += min(it, threshold);
		if (total > M)
			return false;
	}
	return true;
}

int Solution()
{
	int bottom = 1;
	int top = budget.front();

	while (bottom <= top)
	{
		int search = (bottom + top) / 2;

		if (IsPossible(search))
			bottom = search + 1;
		else
			top = search - 1;
	}

	return top;
}

int main()
{
	// 1. input
	cin >> N;
	budget.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> budget[i];
	sort(budget.begin(), budget.end(), greater<int>());

	cin >> M;

	// 2. solution
	cout << Solution();

	return 0;
}
// https://www.acmicpc.net/problem/2805
// pain point: check type size
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
long long M = 0;
int maxHeight = 0;
vector<int> trees;

void cutTree(int low, int high)
{
	if (low > high) return;
	int cutHeight = (low + high) / 2;
	long long sum = 0;

	// find higher tree
	for (int idx = N-1; idx >= 0; --idx)
	{
		if (trees[idx] < cutHeight)
			break;
		sum += trees[idx] - cutHeight;
	}

	// caculate sum
	if (sum >= M)
	{
		if (maxHeight >= cutHeight)
			return;
		maxHeight = cutHeight;
		cutTree(cutHeight+1, high);
	}
	else
		cutTree(low, cutHeight-1);
}

void solution()
{
	// 1. input
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		trees.push_back(tmp);
	}
	sort(trees.begin(), trees.end());

	// 2. find maximum height
	cutTree(0, trees.back());

	cout << maxHeight;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
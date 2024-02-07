// https://www.acmicpc.net/problem/14465
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, B;
vector<bool> broken;

void input()
{
	cin >> N >> K >> B;
	broken.resize(N+1);

	for (int i = 0; i < B; ++i)
	{
		int brokenIdx;
		cin >> brokenIdx;
		broken[brokenIdx] = true;
	}
}

int solution()
{
	int minPair = 0;
	int curPair = 0;

	for (int i = 1; i <= K; ++i)
	{
		if (broken[i])
			curPair++;
	}
	minPair = curPair;

	for (int i = K + 1; i < broken.size(); ++i)
	{
		if (broken[i - K])
			curPair--;
		if (broken[i])
			curPair++;

		minPair = min(minPair, curPair);
	}

	return minPair;
}

int main()
{
	input();
	cout << solution();
	return 0;
}
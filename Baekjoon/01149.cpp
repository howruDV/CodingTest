// https://www.acmicpc.net/problem/1149
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> DP;

void input()
{
	cin >> N;
	DP.resize(N);
	for (int i = 0; i < N; ++i)
	{
		DP[i].resize(3);
		for (int j = 0; j < 3; ++j)
			cin >> DP[i][j];
	}
}

void solution()
{
	for (int i = 1; i < N; ++i)
	{
		DP[i][0] += min(DP[i - 1][1], DP[i - 1][2]);
		DP[i][1] += min(DP[i - 1][2], DP[i - 1][0]);
		DP[i][2] += min(DP[i - 1][0], DP[i - 1][1]);
	}

	int ans = min(DP[N - 1][0], DP[N - 1][1]);
	ans = min(ans, DP[N - 1][2]);
	cout << ans;
}

int main()
{
	input();
	solution();

	return 0;
}
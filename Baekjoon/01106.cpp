// https://www.acmicpc.net/problem/1106
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, N;
vector<pair<int, int>> table;
vector<vector<int>> DP;	// x: 증가하는 고객 수, y: 추가하는 투자비용

void Input()
{
	cin >> C >> N;
	table.resize(N + 1);
	DP.resize(N + 1, vector<int>(C + 1));
	DP[0] = vector<int>(C + 1, 1000);

	for (int i = 1; i <= N; ++i)
	{
		DP[i][0] = 0;
		pair<int, int> item;
		cin >> item.first >> item.second;
		table[i] = item;
	}

	sort(table.begin(), table.end());
}

int Solution()
{
	// y: 추가하는 투자비용
	for (int idx = 1; idx <= N; ++idx)
	{
		int cost = table[idx].first;
		int customer = table[idx].second;

		// x: 증가하는 고객 수
		for (int i = 1; i < customer; ++i)
			DP[idx][i] = min(DP[idx - 1][i], DP[idx][0] + cost);
		for (int i = customer; i <= C; ++i)
			DP[idx][i] = min(DP[idx - 1][i], DP[idx][i % customer] + cost * (i / customer));
	}

	return DP[N][C];
}

int main()
{
	Input();
	cout << Solution();

	return 0;
}
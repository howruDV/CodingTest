// https://www.acmicpc.net/problem/7579
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> memory;
vector<int> cost;
vector<vector<int>> DP;	// DP[i][j] i번째 app까지 탐색, 추가비용 j를 소모하는 최대 메모리

void Input()
{
	int costSum = 0;

	cin >> N >> M;
	memory.resize(N);
	cost.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> memory[i];
	for (int i = 0; i < N; ++i)
	{
		cin >> cost[i];
		costSum += cost[i];
	}

	DP.resize(N + 1, vector<int>(costSum+1));
}

int Solution()
{
	for (int app = 1; app <= N; ++app)
	{
		int curMemory = memory[app - 1];
		int curCost = cost[app - 1];

		for (int extraCost = 0; extraCost < DP[0].size(); ++extraCost)
		{
			if (curCost <= extraCost)
				DP[app][extraCost] = max(DP[app - 1][extraCost], DP[app - 1][extraCost - curCost] + curMemory);
			else
				DP[app][extraCost] = max(DP[app - 1][extraCost], DP[app][extraCost]);
		}
	}

	for (int i = 0; i < DP[0].size(); ++i)
	{
		if (DP[N][i] >= M)
			return i;
	}
	return -1;
}

int main()
{
	Input();
	cout << Solution();
	return 0;
}
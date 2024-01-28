// https://www.acmicpc.net/problem/2583
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int M;
int N;
int K;
vector<vector<bool>> map;

void input()
{
	cin >> M >> N >> K;
	map.resize(M);

	for (int i = 0; i < M; ++i)
		map[i].resize(N);

	for (int i = 0; i < K; ++i)
	{
		pair<int, int> LeftBot, RightTop;
		cin >> LeftBot.first >> LeftBot.second >> RightTop.first >> RightTop.second;

		for (int row = LeftBot.second; row < RightTop.second; ++row)
		{
			for (int col = LeftBot.first; col < RightTop.first; ++col)
				map[row][col] = true;
		}
	}
}

int dfs(int row, int col)
{
	if (row < 0 || row >= M || col < 0 || col >= N || map[row][col] == true)
		return 0;

	map[row][col] = true;
	int nearSize = 1;

	nearSize += dfs(row, col - 1);
	nearSize += dfs(row, col + 1);
	nearSize += dfs(row - 1, col);
	nearSize += dfs(row + 1, col);

	return nearSize;
}

void solution()
{
	priority_queue<int, vector<int>, greater<>> area;

	for (int row = 0; row < M; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			int size = dfs(row, col);
			if (size != 0)
				area.push(size);
		}
	}

	cout << area.size() << endl;
	while (!area.empty())
	{
		cout<< area.top() << " ";
		area.pop();
	}
}

int main()
{
	input();
	solution();

	return 0;
}
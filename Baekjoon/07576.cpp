// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> map;
queue<pair<int, int>> bfs;

void Input(int& total, int& grown)
{
	cin >> M >> N;
	map.resize(N);

	for (int row = 0; row < N; ++row)
	{
		map[row].resize(M);
		for (int col = 0; col < M; ++col)
		{
			cin >> map[row][col];
			if (map[row][col] != -1)
				total++;
			if (map[row][col] == 1)
			{
				grown++;
				bfs.push({ row, col });
			}
		}
	}
}

int Solution(const int total, int grown)
{
	int ans = 0;
	queue<pair<int, int>> nextLevel;
	int dRow[4]{ -1, 1, 0, 0 };
	int dCol[4]{ 0, 0, -1, 1 };

	while (!bfs.empty())
	{
		pair<int, int> cur = bfs.front();
		bfs.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newRow = cur.first + dRow[i];
			int newCol = cur.second + dCol[i];
			if (newRow < 0 || newRow >= N || newCol < 0 || newCol >= M || map[newRow][newCol] != 0)
				continue;

			grown++;
			map[newRow][newCol] = 1;
			nextLevel.push({ newRow, newCol });
		}

		if (bfs.empty() && !nextLevel.empty())
		{
			ans++;
			bfs = nextLevel;
			nextLevel = {};
		}
	}

	return (total == grown) ? ans : -1;
}

int main()
{
	int totalTomato = 0;
	int grownTomato = 0;

	Input(totalTomato, grownTomato);
	if (grownTomato == totalTomato)
		cout << 0;
	else
		cout << Solution(totalTomato, grownTomato);

	return 0;
}
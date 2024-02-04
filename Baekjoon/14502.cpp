// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int M;
vector<vector<int>> map;
vector<pair<int, int>> virus;

void input()
{
	cin >> N >> M;
	map.resize(N);

	for (int row = 0; row < N; ++row)
	{
		map[row].resize(M);
		for (int col = 0; col < M; ++col)
		{
			cin >> map[row][col];
			if (map[row][col] == 2)
				virus.push_back({ row, col });
		}
	}
}

void bfs2(vector<vector<int>>& explore, int row, int col)
{
	queue<pair<int, int>> q;
	explore[row][col] = 0;
	q.push({ row, col });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		if (cur.first < 0 || cur.first >= N || cur.second < 0 || cur.second >= M || explore[cur.first][cur.second] != 0)
			continue;

		explore[cur.first][cur.second] = 2;
		q.push({ cur.first - 1, cur.second });
		q.push({ cur.first + 1, cur.second });
		q.push({ cur.first, cur.second - 1 });
		q.push({ cur.first, cur.second + 1 });
	}
}

void solution()
{
	int ans = 0;

	for (int i = 0; i < N * M; ++i)
	{
		int wallRow1 = i / M;
		int wallCol1 = i % M;

		if (map[wallRow1][wallCol1] == 0)
		{
			for (int j = i + 1; j < N * M; ++j)
			{
				int wallRow2 = j / M;
				int wallCol2 = j % M;

				if (map[wallRow2][wallCol2] == 0)
				{
					for (int k = j + 1; k < N * M; ++k)
					{
						int wallRow3 = k / M;
						int wallCol3 = k % M;

						if (map[wallRow3][wallCol3] == 0)
						{
							vector<vector<int>> simulation = map;
							int count = 0;
							simulation[wallRow1][wallCol1] = 1;
							simulation[wallRow2][wallCol2] = 1;
							simulation[wallRow3][wallCol3] = 1;

							// virus infection
							for (int l = 0; l < virus.size(); ++l)
								bfs2(simulation, virus[l].first, virus[l].second);

							// count safe area
							for (int l = 0; l < N; ++l)
							{
								for (int m = 0; m < M; ++m)
								{
									if (simulation[l][m] == 0)
										count++;
								}
							}

							ans = max(ans, count);
						}
					}
				}
			}
		}
	}

	cout << ans;
}

int main()
{
	input();
	solution();

	return 0;
}
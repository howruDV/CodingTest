// https://www.acmicpc.net/problem/11279
#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K;
vector<vector<bool>> map;

void input()
{
	cin >> M >> N >> K;
	map.resize(N, vector<bool>(M));

	for (int i = 0; i < K; ++i)
	{
		int x, y;
		cin >> x >> y;
		map[y][x] = true;
	}
}

void dfs(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= M || map[row][col] == false)
		return;

	map[row][col] = 0;
	dfs(row - 1, col);
	dfs(row + 1, col);
	dfs(row, col - 1);
	dfs(row, col + 1);
}

int solution()
{
	int ans = 0;

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < M; ++col)
		{
			if (map[row][col])
			{
				dfs(row, col);
				ans++;
			}
		}
	}

	return ans;
}

int main()
{
	vector<int> ans;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		input();
		ans.push_back(solution());
	}

	cout << endl;
	for (int& it: ans)
		cout << it << endl;

	return 0;
}
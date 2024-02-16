// https://www.acmicpc.net/problem/17070
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> map;

void Input()
{
	cin >> N;
	map.resize(N, vector<int>(N));

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
			cin >> map[row][col];
	}
}

int Solution()
{
	int dRow[3] { 0,1,1 }; // hzn, ver, x
	int dCol[3] { 1,0,1 };
	int ans = 0;
	queue<vector<int>> bfs;
	bfs.push({ 0,1,0 });

	while (!bfs.empty())
	{
		int curRow = bfs.front()[0];
		int curCol = bfs.front()[1];
		int curDir = bfs.front()[2];
		bfs.pop();

		if (curRow == N - 1 && curCol == N - 1)
		{
			ans++;
			continue;
		}

		for (int i = 0; i < 3; ++i)
		{
			if (curDir == 0 && i == 1) continue;
			else if (curDir == 1 && i == 0) continue;

			int nextRow = curRow + dRow[i];
			int nextCol = curCol + dCol[i];
			
			if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N || map[nextRow][nextCol] == 1)
				continue;
			if (i == 2 && (map[nextRow - 1][nextCol] == 1 || map[nextRow][nextCol - 1] == 1))
				continue;

			bfs.push({ nextRow, nextCol, i });
		}
	}

	return ans;
}

int main()
{
	Input();
	cout << Solution();
	return 0;
}
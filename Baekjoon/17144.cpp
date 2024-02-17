// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
using namespace std;

enum{WIDTH,HEIGHT,};
enum{LEFT,RIGHT,};
enum{UP,DOWN,};

int R, C, T;
vector<vector<int>> map;
vector<int> cleanerPos;

void Input()
{
	cin >> R >> C >> T;
	map.resize(R, vector<int>(C));

	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			cin >> map[row][col];
			if (map[row][col] == -1)
				cleanerPos.push_back(row);
		}
	}
}

void SpreadDust(vector<vector<int>>& map)
{
	int dRow_dust[4] = { -1,1,0,0 };
	int dCol_dust[4] = { 0,0,-1,1 };

	vector<vector<int>> dtMap(R, vector<int>(C));

	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			if (map[row][col] == 0 && map[row][col] == -1)
				continue;

			int spreadTotal = 0;
			int spreadValue = map[row][col] / 5;

			for (int i = 0; i < 4; ++i)
			{
				int spreadRow = row + dRow_dust[i];
				int spreadCol = col + dCol_dust[i];
				if (spreadRow < 0 || spreadRow >= R || spreadCol < 0 || spreadCol >= C || map[spreadRow][spreadCol] == -1)
					continue;

				dtMap[spreadRow][spreadCol] += spreadValue;
				spreadTotal += spreadValue;
			}

			dtMap[row][col] -= spreadTotal;
		}
	}

	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
			map[row][col] += dtMap[row][col];
	}
}

int PullVec(vector<vector<int>>& map, bool dir, bool progress, int rowFrom, int rowTo = 0, int col = 0)
{
	int corner = 0;

	if (dir == WIDTH)
	{
		if (progress == RIGHT)
			corner = map[rowFrom][C - 1];
		else
			corner = map[rowFrom][0];

		for (int i = 0; i < C-1; ++i)
		{
			if (progress == RIGHT)
			{
				if (map[rowFrom][C - 2 - i] == -1)
					map[rowFrom][C - 1 - i] = 0;
				else
					map[rowFrom][C - 1 - i] = map[rowFrom][C - 2 - i];
			}
			else
				map[rowFrom][i] = map[rowFrom][i + 1];
		}
	}
	else if (dir == HEIGHT)
	{
		if (progress == DOWN)
			corner = map[rowTo][col];
		else
			corner = map[rowFrom][col];

		for (int i = rowFrom; i < rowTo; ++i)
		{
			if (progress == DOWN)
				map[rowTo - (i - rowFrom)][col] = map[rowTo - (i - rowFrom) - 1][col];
			else
				map[i][col] = map[i + 1][col];
		}
	}

	return corner;
}

int Solution()
{
	int ans = 0;

	for (int i = 0; i < T; ++i)
	{
		// 1. spread dust
		SpreadDust(map);

		// 2. run air cleaner
		PullVec(map, HEIGHT, DOWN, 0, cleanerPos[0] - 1);
		PullVec(map, WIDTH, LEFT, 0);
		PullVec(map, HEIGHT, UP, 0, cleanerPos[0], C - 1);
		PullVec(map, WIDTH, RIGHT, cleanerPos[0]);

		PullVec(map, HEIGHT, UP, cleanerPos[1] + 1, R - 1);
		PullVec(map, WIDTH, LEFT, R - 1);
		PullVec(map, HEIGHT, DOWN, cleanerPos[1], R - 1, C - 1);
		PullVec(map, WIDTH, RIGHT, cleanerPos[1]);
	}

	// 3. count dust
	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			if (map[row][col] == -1)
				continue;
			ans += map[row][col];
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
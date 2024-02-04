// https://www.acmicpc.net/problem/21736
#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
int ans;
vector<vector<char>> map;

void input(int& _outRow, int& _outCol)
{
	cin >> N >> M;
	map.resize(N);
	for (int row = 0; row < N; ++row)
	{
		map[row].resize(M);
		for (int col = 0; col < M; ++col)
		{
			cin >> map[row][col];
			if (map[row][col] == 'I')
			{
				_outRow = row;
				_outCol = col;
			}
		}
	}
}

void dfs(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= M || map[row][col] == 'V' || map[row][col] == 'X') return;

	if (map[row][col] == 'P')
		ans++;
	map[row][col] = 'V';

	dfs(row - 1, col);
	dfs(row + 1, col);
	dfs(row, col - 1);
	dfs(row, col + 1);
}

int main()
{
	int doyeonRow, doyenCol;
	input(doyeonRow, doyenCol);
	dfs(doyeonRow, doyenCol);

	if (ans == 0)
		cout << "TT";
	else
		cout << ans;
	return 0;
}
// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R;
int C;
vector<vector<char>> map;

void input()
{
	cin >> R >> C;
	map.resize(R);

	for (int row = 0; row < R; ++row)
	{
		map[row].resize(C);
		for (int col = 0; col < C; ++col)
			cin >> map[row][col];
	}
}

int dfs(int row, int col, vector<bool>& record)
{
	if (row < 0 || row >= R || col < 0 || col >= C
		|| record[map[row][col] - 'A'])
		return 0;

	int len = 1;
	record[map[row][col] - 'A'] = true;

	len = max(len, 1 + dfs(row - 1, col, record));
	len = max(len, 1 + dfs(row + 1, col, record));
	len = max(len, 1 + dfs(row, col - 1, record));
	len = max(len, 1 + dfs(row, col + 1, record));

	record[map[row][col] - 'A'] = false;

	return len;
}

int main()
{
	vector<bool> vec(26);

	input();
	cout << dfs(0, 0, vec);

	return 0;
}
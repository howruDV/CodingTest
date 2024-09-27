// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<char>> map;

void Input()
{
	cin >> N;
	map.resize(N, vector<char>(N));

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
			cin >> map[row][col];
	}
}

int Dfs(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= N || map[row][col] == '0')
		return 0;

	int count = 1;
	map[row][col] = '0';

	count += Dfs(row - 1, col);
	count += Dfs(row + 1, col);
	count += Dfs(row, col - 1);
	count += Dfs(row, col + 1);

	return count;
}

void Solution()
{
	vector<int> ans{};

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			if (map[row][col] != '0')
				ans.push_back(Dfs(row, col));
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size();
	for (int& it : ans)
		cout << endl << it;
}

int main()
{
	Input();
	Solution();

	return 0;
}
// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<char>> map;
int countRG;
int countArea;

void input()
{
	cin >> N;
	map.resize(N);

	for (int row = 0; row < N; ++row)
	{
		map[row].resize(N);
		for (int col = 0; col < N; ++col)
			cin >> map[row][col];
	}
}

void bfs(int r, int c)
{
	queue < pair<pair<int, int>, char>> explore;
	queue < pair<pair<int, int>, char>> nextRG;
	explore.push({ {r,c}, map[r][c] });
	countArea++;

	while (!explore.empty() || !nextRG.empty())
	{
		pair<pair<int, int>, char> curColor;
		bool bConvertRG = false;

		// 1. find current node
		if (!explore.empty())
		{
			curColor = explore.front();
			explore.pop();
		}
		else
		{
			bConvertRG = true;
			curColor = nextRG.front();
			nextRG.pop();
		}

		int row = curColor.first.first;
		int col = curColor.first.second;
		char ch = curColor.second;
		bool boundCheck = row < 0 || row >= N || col < 0 || col >= N;
		
		// 2. check validity
		if (ch == '0' || boundCheck || map[row][col] == '0' || map[row][col] != ch)
		{
			if (!boundCheck && ((ch == 'R' && map[row][col] == 'G') || (ch == 'G' && map[row][col] == 'R')))
				nextRG.push({ {row, col}, map[row][col]});
			continue;
		}

		map[row][col] = '0';
		if (bConvertRG)
		{
			countRG++;
			countArea++;
		}

		// 3. push next node
		explore.push({ {row, col + 1}, ch });
		explore.push({ {row, col - 1}, ch });
		explore.push({ {row + 1, col}, ch });
		explore.push({ {row - 1, col}, ch });
	}
}

void solution()
{
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			if (map[row][col] != '0')
			{
				bfs(row, col);
			}
		}
	}

	cout << countArea << " " << countArea - countRG;
}

int main()
{
	input();
	solution();

	return 0;
}
// https://www.acmicpc.net/problem/14500
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum{BLOCK14, BLOCK22, BLOCK32};

// BLOCK14
vector<vector<vector<int>>> BLOCK14_FILTER{
	vector<vector<int>>{{1,1,1,1}},
};

// BLOCK22
vector<vector<vector<int>>> BLOCK22_FILTER{
	vector<vector<int>>{{1,1},{1,1}},
};

// BLOCK32
vector<vector<vector<int>>> BLOCK32_FILTER{
	vector<vector<int>>{{1,0},{1,0},{1,1}},
	vector<vector<int>>{{1,0},{1,1},{0,1}},
	vector<vector<int>>{{1,0},{1,1},{1,0}},
};

int N, M;
vector<vector<int>> map;

void Input()
{
	cin >> N >> M;
	map.resize(N, vector<int>(M));

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < M; ++col)
			cin >> map[row][col];
	}
}

bool IsPossible(int row, int col, int height, int width)
{
	int leftBotRow = row + height - 1;
	int leftBotCol = col + width - 1;
	if (leftBotRow < N && leftBotCol < M)
		return true;
	return false;
}

int GetMaxScoreByType(int type, int row, int col, bool flip = false, bool rotate = false)
{
	int maxScore = 0;
	vector<vector<vector<int>>>* filterList = nullptr;
	vector<pair<bool, bool>> range{ {false, false} };

	if (type == BLOCK14)
		filterList = &BLOCK14_FILTER;
	else if (type == BLOCK22)
		filterList = &BLOCK22_FILTER;
	else
		filterList = &BLOCK32_FILTER;

	if (flip)
	{
		range.push_back({ true, false });
		range.push_back({ false, true });
		range.push_back({ true, true });
	}

	while (!range.empty())
	{
		bool flipRow = range.back().first;
		bool flipCol = range.back().second;
		range.pop_back();

		for (int filterIdx = 0; filterIdx < filterList->size(); ++filterIdx)
		{
			vector<vector<int>>& curFilter = (*filterList)[filterIdx];
			int curFilterScore = 0;

			for (int i = 0; i < curFilter.size(); ++i)
			{
				for (int j = 0; j < curFilter[0].size(); ++j)
				{
					if (!curFilter[i][j])
						continue;

					// case: flip
					int dRow = i;
					int dCol = j;
					if (flipRow) dRow = curFilter.size() - 1 - i;
					if (flipCol) dCol = curFilter[0].size() - 1 - j;

					// case: rotate
					int rotateRow = row + dRow;
					int rotateCol = col + dCol;
					if (rotate)
					{
						rotateRow = row + dCol;
						rotateCol = col +dRow;
					}

					curFilterScore += map[rotateRow][rotateCol];
				}
			}

			maxScore = max(maxScore, curFilterScore);
		}
	}

	return maxScore;
}

int Solution()
{
	int ans = 0;

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < M; ++col)
		{
			// case: 1*4
			if (IsPossible(row, col, 1, 4))
			{
				ans = max(ans, GetMaxScoreByType(BLOCK14, row, col));
			}
			if (IsPossible(row, col, 4, 1))
				ans = max(ans, GetMaxScoreByType(BLOCK14, row, col, false, true));

			// case: 2*2
			if (IsPossible(row, col, 2, 2))
				ans = max(ans, GetMaxScoreByType(BLOCK22, row, col));

			// case: 3*2
			if (IsPossible(row, col, 3, 2))
				ans = max(ans, GetMaxScoreByType(BLOCK32, row, col, true));
			if (IsPossible(row, col, 2, 3))
				ans = max(ans, GetMaxScoreByType(BLOCK32, row, col, true, true));
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
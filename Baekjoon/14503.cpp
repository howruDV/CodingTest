// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int R, C, D;
vector<vector<int>> map;
int dRow[4] = { -1,0,1,0 };	// N,E,S,W
int dCol[4] = { 0,1,0,-1 };

void Input()
{
	cin >> N >> M;
	cin >> R >> C >> D;
	map.resize(N);

	for (int row = 0; row < N; ++row)
	{
		map[row].resize(M);
		for (int col = 0; col < M; ++col)
			cin >> map[row][col];
	}
}

int Solution()
{
	int ans = 0;

	while (map[R][C] != 1)
	{
		bool bMove = false;

		if (map[R][C] == 0)
		{
			map[R][C] = -1;
			ans++;
		}
		
		for (int i = 1; i <= 4; ++i)
		{
			int idx = (D - i + 4) % 4;
			int row = R + dRow[idx];
			int col = C + dCol[idx];
			if (row>=0 && row<N && col>=0 && col<M && map[row][col] == 0)
			{
				R = row;
				C = col;
				D = idx;
				bMove = true;
				break;
			}
		}
		if (bMove)
			continue;
		else
		{
			R -= dRow[D];
			C -= dCol[D];
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
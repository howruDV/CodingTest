// https://www.acmicpc.net/problem/9465
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> sticker(2);

void input()
{
	cin >> N;

	for (int i = 0; i < 2; ++i)
	{
		sticker[i].resize(N);
		for (int j = 0; j < N; ++j)
			cin >> sticker[i][j];
	}
}

int solution()
{
	sticker[0][1] += sticker[1][0];
	sticker[1][1] += sticker[0][0];

	for (int i = 2; i < N; ++i)
	{
		sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2]);
		sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2]);
	}

	return max(sticker[0][N-1], sticker[1][N-1]);
}

int main()
{
	vector<int> ans;
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		input();
		ans.push_back(solution());
	}

	for (int i = 0; i < T; ++i)
		cout << ans[i] << endl;

	return 0;
}
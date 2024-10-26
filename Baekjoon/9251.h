#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void b9251()
{
	string a;
	string b;

	// 0. input
	cin >> a >> b;

	// 1. find LCS
	// DP : b의 한 글자씩 비교하면서, 현재까지 가장 긴 문자열 길이 기록
	vector<vector<int>> DP(a.size() + 1, vector<int>(b.size() + 1));

	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			// case : 글자가 같다면
			if (a[i - 1] == b[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			// case : 글자가 다르다면
			// 현재 갱신중인 길이와, 이전 루프에서 지금시점 길이와 비교
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[a.size()][b.size()];

	// 2. get LCS
	string ans;
	int i = a.size();
	int j = b.size();

	while (ans.size() < DP[a.size()][b.size()])
	{
		// case : 위로 같은경우 (이전 루프에서 갱신된 값인 경우)
		if (DP[i-1][j] == DP[i][j])
		{
			i = i - 1;
		}
		// case : 옆으로 같은경우 (현재 진행에서 갱신된 값인 경우)
		else if (DP[i][j - 1] == DP[i][j])
		{
			j = j - 1;
		}
		// case : 같지 않은 경우 (현재 경신된 경우)
		else
		{
			ans += a[i - 1];
			i = i - 1;
			j = j - 1;
		}
	}

	reverse(ans.begin(), ans.end());
}
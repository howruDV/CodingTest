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
	// DP : b�� �� ���ھ� ���ϸ鼭, ������� ���� �� ���ڿ� ���� ���
	vector<vector<int>> DP(a.size() + 1, vector<int>(b.size() + 1));

	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			// case : ���ڰ� ���ٸ�
			if (a[i - 1] == b[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			// case : ���ڰ� �ٸ��ٸ�
			// ���� �������� ���̿�, ���� �������� ���ݽ��� ���̿� ��
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
		// case : ���� ������� (���� �������� ���ŵ� ���� ���)
		if (DP[i-1][j] == DP[i][j])
		{
			i = i - 1;
		}
		// case : ������ ������� (���� ���࿡�� ���ŵ� ���� ���)
		else if (DP[i][j - 1] == DP[i][j])
		{
			j = j - 1;
		}
		// case : ���� ���� ��� (���� ��ŵ� ���)
		else
		{
			ans += a[i - 1];
			i = i - 1;
			j = j - 1;
		}
	}

	reverse(ans.begin(), ans.end());
}
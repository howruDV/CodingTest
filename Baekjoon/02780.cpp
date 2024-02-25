// https://www.acmicpc.net/problem/2780
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<vector<int>> dp; // dp[i][j] 비밀번호의 i번째 수가 j인 경우의 수

void InitDp(int size)
{
	dp.resize(size, vector<int>(10));
	dp[0] = vector<int>(10, 1);
	
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			switch (j)
			{
			case 0:
				dp[i][j] = dp[i - 1][7];
				break;
			case 1:
				dp[i][j] = dp[i - 1][2] + dp[i - 1][4];
				break;
			case 2:
				dp[i][j] = dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5];
				break;
			case 3:
				dp[i][j] = dp[i - 1][2] + dp[i - 1][6];
				break;
			case 4:
				dp[i][j] = dp[i - 1][1] + dp[i - 1][5] + dp[i-1][7];
				break;
			case 5:
				dp[i][j] = dp[i - 1][2] + dp[i - 1][4] + dp[i-1][6] + dp[i-1][8];
				break;
			case 6:
				dp[i][j] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
				break;
			case 7:
				dp[i][j] = dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0];
				break;
			case 8:
				dp[i][j] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
				break;
			case 9:
				dp[i][j] = dp[i - 1][6] + dp[i - 1][8];
				break;
			}

			dp[i][j] %= 1234567;
		}
	}
}

int Solution(int len)
{
	int ans = 0;

	for (int i = 0; i < 10; ++i)
		ans = (ans + dp[len-1][i]) % 1234567;
	return ans;
}

int main()
{
	cin >> T;

	vector<int> N(T);
	int maxN = 0;

	for (int i = 0; i < T; ++i)
	{
		cin >> N[i];
		maxN = max(maxN, N[i]);
	}
	InitDp(maxN);

	for (int i = 0; i < T; ++i)
		cout << Solution(N[i]) << endl;

	return 0;
}
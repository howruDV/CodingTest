// https://www.acmicpc.net/problem/2110
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> homePos;

int Solution()
{
	int ans = 0;
	int lowerBound = 1;
	int upperBound = homePos[N - 1] - homePos[0];

	// check installation count by dist (dist adjust: binary search)
	while (lowerBound <= upperBound)
	{
		int dist = (lowerBound + upperBound) / 2;
		int prevPos = homePos[0];
		int count = 1;

		for (int i = 1; i < N; ++i)
		{
			if (homePos[i] - prevPos >= dist)
			{
				prevPos = homePos[i];
				if (count++ >= C) break;
			}
		}

		if (count < C)
			upperBound = dist - 1;
		else
		{
			ans = max(ans, dist);
			lowerBound = dist + 1;
		}
	}

	return ans;
}

int main()
{
	cin >> N >> C;
	homePos.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> homePos[i];
	sort(homePos.begin(), homePos.end());

	cout << Solution();
	return 0;
}
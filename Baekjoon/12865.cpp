// https://www.acmicpc.net/problem/12865
// (1) Fractional: Greedy
// (2) Knapsack: DP (THIS!)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> W{-1};
vector<int> V{-1};
vector<vector<int>> DP; // 2D DP: item idx, weight

void Input()
{
	cin >> N >> K;
	DP.push_back(vector<int>(K+1));

	for (int i = 0; i < N; ++i)
	{
		int w;
		int v;
		cin >> w >> v;
		
		if (w <= K)
		{
			DP.push_back(vector<int>(K+1));
			W.push_back(w);
			V.push_back(v);
		}
	}
}

int Solution()
{
	// find max weight's max value by item idx order
	for (int idx = 1; idx < V.size(); ++idx)
	{
		for (int weight = 1; weight <= K; weight++)
		{
			if (weight < W[idx])
				DP[idx][weight] = DP[idx - 1][weight];
			else
				DP[idx][weight] = max(DP[idx - 1][weight], DP[idx - 1][weight - W[idx]] + V[idx]);
		}
	}

	return DP[V.size()-1][K];
}

int main()
{
	Input();
	cout << Solution();
	return 0;
}
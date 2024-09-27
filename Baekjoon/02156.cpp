// https://www.acmicpc.net/problem/2156
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> cup;
vector<vector<int>> DP (2);


void Input()
{
	cin >> N;
	cup.resize(N);
	DP[0].resize(N, vector<int>(2));
	DP[1].resize(N);

	for (int i = 0; i < N; ++i)
		cin >> cup[i];
}

int Solution()
{
	for (int i = 0; i < N; ++i)
	{
		DP[0][i] = DP[];
	}

	return cup[0];
}

int main()
{
	Input();
	cout << Solution();

	return 0;
}
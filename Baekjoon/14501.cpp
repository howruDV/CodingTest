// https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> TPtable;
vector<int> DPtable;

void Dp(int idx, int& maxSum)
{
	// note maximum profit "DAYidx" can get
	DPtable[idx] = max(maxSum, DPtable[idx]);
	maxSum = DPtable[idx];

	pair<int, int>& CurValue = TPtable[idx];
	if (idx + CurValue.first <= n)
		DPtable[idx + CurValue.first] = max(TPtable[idx].second + DPtable[idx], DPtable[idx + CurValue.first]);
}

void solution()
{
	// 1. input
	int ans = 0;

	cin >> n;
	TPtable.resize(n+1);
	DPtable.resize(n+1);

	for (int i = 0; i < n; ++i)
		cin >> TPtable[i].first >> TPtable[i].second;

	// 2. caculate max profit
	for (int i = 0; i <= n; ++i)
		Dp(i, ans);

	cout << ans;
}

int main()
{
	solution();
	return 0;
}
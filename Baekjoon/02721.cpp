// https://www.acmicpc.net/problem/2721
#include <iostream>
#include <vector>
using namespace std;

int DP[300];

int Tri(int n)
{
	if (DP[n])
		return DP[n];

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += i;

	DP[n] = ans;
	return ans;
}

int Sum(int n)
{
	int sum = 0;

	for (int i = 1; i <= n; ++i)
		sum += i * Tri(i + 1);
	return sum;
}

int main()
{
	int T, N;
	vector<int> ans;
	
	// input
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		ans.push_back(Sum(N));
	}

	// output
	for (int& it : ans)
		cout << it << endl;

	return 0;
}
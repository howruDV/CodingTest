// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> P;

void Input()
{
	cin >> N;
	P.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> P[i];
}

int Solution()
{
	int ans = 0;
	int sum = 0;

	sort(P.begin(), P.end());

	for (int i = 0; i < P.size(); ++i)
	{
		sum += P[i];
		ans += sum;
	}

	return ans;
}

int main()
{
	Input();
	cout << Solution();

	return 0;
}
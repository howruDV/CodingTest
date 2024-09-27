// https://www.acmicpc.net/problem/10810
#include <iostream>
#include <vector>
using namespace std;

int N, M;

void Solution()
{
	vector<int> basket(N);

	for (int l = 0; l < M; ++l)
	{
		int i = 0;
		int j = 0;
		int k = 0;

		cin >> i >> j >> k;

		for (int m = i-1; m < j; ++m)
			basket[m] = k;
	}

	for (int& it : basket)
		cout << it << " ";
}

int main()
{
	cin >> N >> M;
	Solution();

	return 0;
}
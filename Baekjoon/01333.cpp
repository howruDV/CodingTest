// https://www.acmicpc.net/problem/1333
#include <iostream>
using namespace std;

int N, L, D;

int Solution()
{
	int time = 0;
	int callTime = 0;

	for (int i = 0; i < N; ++i)
	{
		time += L; // finish time
		while (callTime < time)
			callTime += D;

		time += 5;
		if (callTime < time)
			return callTime;
	}

	return callTime;
}

int main()
{
	cin >> N >> L >> D;
	cout << Solution();

	return 0;
}
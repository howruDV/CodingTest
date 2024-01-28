// https://www.acmicpc.net/problem/1697
#include <iostream>
#include <queue>
using namespace std;

int N;
int K;
int sec[100001];

void solution()
{
	// 1. input
	cin >> N >> K;
	sec[N] = true;

	// 2. find - bfs
	queue<int> move;
	move.push(N);

	while (sec[K] == 0)
	{
		int curPos = move.front();

		if (curPos + 1 <= 100000 && sec[curPos + 1] == 0)
		{
			sec[curPos + 1] = sec[curPos] + 1;
			move.push(curPos + 1);
		}
		if (curPos - 1 >= 0 && sec[curPos - 1] == 0)
		{
			sec[curPos - 1] = sec[curPos] + 1;
			move.push(curPos - 1);
		}
		if (curPos * 2 <= 100000 && sec[curPos * 2] == 0)
		{
			sec[curPos * 2] = sec[curPos] + 1;
			move.push(curPos * 2);
		}

		move.pop();
	}

	cout << sec[K] - 1;
}

int main()
{
	solution();
	return 0;
}
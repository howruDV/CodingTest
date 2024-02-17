// https://www.acmicpc.net/problem/12851
#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visit[200000] = { false, };

void Solution()
{
	queue<pair<int, int>> bfs;	// pos, time
	int smallestTime = 100000;
	int ans = 0;

	bfs.push({ N,0 });

	while (!bfs.empty())
	{
		int curPos = bfs.front().first;
		int curTime = bfs.front().second;
		bfs.pop();

		visit[curPos] = true;

		if (curPos == K)
		{
			if (curTime == smallestTime)
				ans++;
			else if (curTime < smallestTime)
			{
				ans = 1;
				smallestTime = curTime;
			}

			continue;
		}

		if (++curTime > smallestTime)
			continue;

		if (curPos*2 >= 0 && curPos*2 < 200000 && !visit[curPos*2])
			bfs.push({ curPos * 2, curTime });
		if (curPos+1 >= 0 && curPos+1 < 200000 && !visit[curPos+1])
			bfs.push({curPos + 1, curTime });
		if (curPos-1 >= 0 && curPos-1 < 200000 && !visit[curPos-1])
			bfs.push({curPos - 1, curTime });
	}

	cout << smallestTime << endl << ans;
}

int main()
{
	cin >> N >> K;
	Solution();

	return 0;
}
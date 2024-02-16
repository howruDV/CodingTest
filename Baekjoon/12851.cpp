// https://www.acmicpc.net/problem/12851
#include <iostream>
#include <vector>
#define LEN_MAX ((N >= K) ? N : K*2)
using namespace std;

int N, K;
vector<bool> visited;
int prevTime = INT_MAX;
int ans = 0;

void Dfs(int pos, int time)
{
	if (pos < 0 || pos >= LEN_MAX || visited[pos])
		return;
	else if (ans != 0 && time > prevTime) return;
	else if (pos == K)
	{
		if (prevTime > time)
		{
			prevTime = time;
			ans = 1;
		}
		else if (prevTime == time)
			ans++;
	}

	time++;
	visited[pos] = true;

	Dfs(pos * 2, time);
	Dfs(pos + 1, time);
	Dfs(pos - 1, time);

	visited[pos] = false;
}

int main()
{
	cin >> N >> K;
	visited.resize(LEN_MAX, false);

	Dfs(N, 0);
	cout << prevTime << endl << ans;

	return 0;
}
// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int E;
vector<vector<int>> graph;
vector<bool> visit;

void input()
{
	cin >> N >> E;
	graph.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < E; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
}

void solution()
{
	int ans = 0;
	queue<int> explore;
	explore.push(1);

	while (!explore.empty())
	{
		int cur = explore.front();
		explore.pop();
		if (visit[cur]) continue;

		visit[cur] = true;
		ans++;
		for (int it : graph[cur])
			explore.emplace(it);
	}

	cout << ans - 1;
}

int main()
{
	input();
	solution();
	return 0;
}
// Leetcode 0332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	// Idea : 현재 방문한 노드는 확정된 다음 방문 경로의 앞부분임
	// 재귀 종료 조건 : 더이상 dfs를 돌 수 없는 곳은 현재 방문 가능한 가장 마지막 노드
	void dfs(string current, unordered_map<string, deque<string>>& graph, vector<string>& path)
	{
		while (!graph[current].empty())
		{
			string next = graph[current].front();
			graph[current].pop_front();
			dfs(next, graph, path);
		}

		path.push_back(current);
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		// 0. Graph 구성
		unordered_map<string, deque<string>> Graph;
		set<string> Keys;

		for (vector<string> ticket : tickets)
		{
			Keys.insert(ticket[0]);
			Graph[ticket[0]].push_back(ticket[1]);
		}

		for (string key : Keys)
		{
			sort(Graph[key].begin(), Graph[key].end());
		}

		// 1. Itinerary 찾음
		vector<string> path;
		dfs("JFK", Graph, path);

		reverse(path.begin(), path.end());
		return path;
	}
};
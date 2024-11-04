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
	// Idea : ���� �湮�� ���� Ȯ���� ���� �湮 ����� �պκ���
	// ��� ���� ���� : ���̻� dfs�� �� �� ���� ���� ���� �湮 ������ ���� ������ ���
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
		// 0. Graph ����
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

		// 1. Itinerary ã��
		vector<string> path;
		dfs("JFK", Graph, path);

		reverse(path.begin(), path.end());
		return path;
	}
};
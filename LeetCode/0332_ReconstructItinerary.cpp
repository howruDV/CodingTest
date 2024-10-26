// LeetCode 0332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> ans;
	unordered_map<string, vector<string>> graph;
	unordered_map<string, int> visitRemain;

	void dfs(const string& curPos, vector<string>& path)
	{
		if (!ans.empty() || visitRemain[curPos] || path.size() > visitRemain.size())
			return;

		// 방문처리
		visitRemain[curPos] = true;
		path.push_back(curPos);

		if (path.size() == visitRemain.size())
		{
			ans = path;
			return;
		}

		// 다른 곳으로 이동
		for (int i = 0; i < graph[curPos].size(); ++i)
		{
			dfs(graph[curPos][i], path);
		}

		visitRemain[curPos] = false;
		path.pop_back();
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		// 1. create graph
		for (vector<string> ticket : tickets)
		{
			graph[ticket.front()].push_back(ticket.back());
			visitRemain[ticket.front()]++;
			visitRemain[ticket.back()]++;
		}

		// 2. dfs
		vector<string> keys;
		vector<string> path;

		for (const auto& pair : visitRemain)
		{
			keys.push_back(pair.first);
		}

		for (int i = 0; i < keys.size(); ++i)
		{
			dfs(keys[i], path);
		}

		return ans;
	}
};
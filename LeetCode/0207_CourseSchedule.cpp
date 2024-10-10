// LeetCode 0207. Course Schedule
// https://leetcode.com/problems/course-schedule/

#include <vector>
using namespace std;

class Solution {
	enum class VisitType
	{
		None,
		Visited,
		Checked,
	};

public:
	vector<VisitType> visited;

	bool dfs(vector<vector<int>>& graph, int idx)
	{
		if (visited[idx] == VisitType::Visited)
			return true;
		else if (visited[idx] == VisitType::Checked)
			return false;

		visited[idx] = VisitType::Visited;

		for (int i = 0; i < graph[idx].size(); ++i)
		{
			if (dfs(graph, graph[idx][i]))
				return true;
		}

		visited[idx] = VisitType::Checked;

		return false;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> Graph(numCourses, vector<int>());
		visited.resize(numCourses, VisitType::None);

		// 0. Graph 생성
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			int From = prerequisites[i].back();
			int To = prerequisites[i].front();
			Graph[To].push_back(From);
		}

		// 1. 사이클 확인
		for (int i = 0; i < numCourses; ++i)
		{
			if (visited[i] == VisitType::Checked)
				continue;

			if (dfs(Graph, i))
				return false;
		}

		return true;
	}
};
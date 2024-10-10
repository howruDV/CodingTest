// LeetCode 0200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	// ========
	// (0) DFS
	// ========
	bool dfs(int h, int w, vector<vector<char>>& grid)
	{
		if (h < 0 || h >= grid.size() || w < 0 || w >= grid[0].size() || grid[h][w] != '1')
			return false;

		char ans = grid[h][w];
		grid[h][w] = '0';

		dfs(h - 1, w, grid);
		dfs(h + 1, w, grid);
		dfs(h, w - 1, grid);
		dfs(h, w + 1, grid);

		return true;
	}

	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;

		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					dfs(i, j, grid);
					ans++;
				}
			}
		}

		return ans;
	}

	// ========
	// (1) BFS
	// ========
	int numIslands_bfs(vector<vector<char>>& grid) {
		int ans = 0;
		deque<pair<int, int>> queue;

		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] != '1')
					continue;

				ans++;
				queue.push_back({ i, j });

				while (!queue.empty())
				{
					int h = queue.front().first;
					int w = queue.front().second;
					queue.pop_front();

					if (h < 0 || h >= grid.size() || w < 0 || w >= grid[0].size() || grid[h][w] != '1')
						continue;

					grid[h][w] = '0';
					queue.push_back({ h, w - 1 });
					queue.push_back({ h, w + 1 });
					queue.push_back({ h - 1, w });
					queue.push_back({ h + 1, w });
				}
			}
		}

		return ans;
	}
};
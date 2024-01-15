// LeetCode 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <vector>
using namespace std;

// DFS ver
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    void DFS(vector<vector<char>>& grid, int i, int j)
    {
        // exit
        if (i < 0 || i >= grid.size()
            || j < 0 || j >= grid[0].size()
            || grid[i][j] != '1')
            return;

        grid[i][j] = '0';

        // search nearby
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i + 1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

// BFS ver
class Solution1 {
public:
    void BFS() {}
    int numIslands(vector<vector<char>>& grid) {
    }
};
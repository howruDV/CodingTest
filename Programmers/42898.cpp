// Programmers 42898
// https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ===========================================
// Try 1
// @Main Idea : bfs로 가장 짧은 경로 모두 탐색
// ===========================================
int solution_0(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	vector<vector<bool>> graph(n, vector<bool>(m));

	// make graph
	for (vector<int> puddle : puddles)
	{
		graph[puddle[1] - 1][puddle[0] - 1] = true;
	}

	// bfs
	int shortestLength = -1;
	queue<vector<int>> queue; // col, row, length
	queue.push({ 0, 0, 0 });

	while (!queue.empty())
	{
		const int curCol = queue.front()[0];
		const int curRow = queue.front()[1];
		const int curLength = queue.front()[2];
		queue.pop();

		if (curCol < 0 || curCol >= m || curRow < 0 || curRow >= n || graph[curRow][curCol])
			continue;
		else if (curCol == m - 1 && curRow == n - 1)
		{
			if (shortestLength == -1 || curLength == shortestLength)
			{
				shortestLength = curLength;
				answer++;
			}

			continue;
		}

		queue.push({ curCol + 1, curRow, curLength + 1 });
		queue.push({ curCol, curRow + 1, curLength + 1 });
	}

	return answer % 1000000007;
}

// ===========================================
// Try 2
// @Main Idea : DP로 현재 움직인 횟수 카운트 후, dfs로 경로탐색
// ===========================================
void dfs(const int col, const int row, const vector<vector<int>>& graph, int& outPathCount)
{
	if (col <= 0 && row <= 0 || graph[row][col] == -1)
		return;
	if (col == 1 && row == 1)
	{
		outPathCount++;
		return;
	}

	// 현재 위치로 올 수 있는 왼쪽, 위쪽으로 진행
	const int curPathLen = graph[row][col];

	if (graph[row - 1][col] + 1 == curPathLen)
	{
		dfs(col, row - 1, graph, outPathCount);
	}
	if (graph[row][col - 1] + 1 == curPathLen)
	{
		dfs(col - 1, row, graph, outPathCount);
	}
}

int solution_2(int m, int n, vector<vector<int>> puddles) {
	// 1. 진행하지 못하는 DP 기록
	vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
	for (vector<int> puddle : puddles)
	{
		DP[puddle[1]][puddle[0]] = -1;
	}

	// 2. DP 구성
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			// case : 외곽 처리
			if (i == 0 || j == 0)
			{
				DP[i][j] = -1;
				continue;
			}
			// case : 웅덩이
			if (DP[i][j] == -1)
				continue;

			if (DP[i - 1][j] != -1 && DP[i][j - 1] != -1)
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) + 1;
			}
			else if (DP[i - 1][j] == -1 && DP[i][j - 1] == -1)
			{
				continue;
			}
			else if (DP[i][j - 1] == -1)
			{
				DP[i][j] = DP[i - 1][j] + 1;
			}
			else
			{
				DP[i][j] = DP[i][j - 1] + 1;
			}
		}
	}

	// 3. dfs
	int answer = 0;
	dfs(m, n, DP, answer);

	return answer % 1000000007;
}

// ===========================================
// Try 3 : DP로 현재 분기한 경로 기록
// ===========================================
int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

	// 1. 웅덩이 기록
	for (vector<int> puddle : puddles)
	{
		DP[puddle[1]][puddle[0]] = -1;
	}

	// 2. DP
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			// case : 웅덩이
			if (DP[i][j] == -1)
				continue;
			// case : 출발지
			if (i == 1 && j == 1)
			{
				DP[i][j] = 1;
				continue;
			}

			if (DP[i - 1][j] != -1 && DP[i][j - 1] != -1)
			{
				DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % 1000000007;
			}
			else if (DP[i - 1][j] == -1 && DP[i][j - 1] == -1)
			{
				DP[i][j] = -1;
			}
			else if (DP[i][j - 1] == -1)
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				DP[i][j] = DP[i][j - 1];
			}
		}
	}

	return DP[n][m];
}

#include <iostream>
int main()
{
	int ans = solution(4, 3, { {2,2} });
	cout << ans;
	return 0;
}
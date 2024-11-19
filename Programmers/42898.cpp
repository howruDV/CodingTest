// Programmers 42898
// https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ===========================================
// Try 1
// @Main Idea : bfs�� ���� ª�� ��� ��� Ž��
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
// @Main Idea : DP�� ���� ������ Ƚ�� ī��Ʈ ��, dfs�� ���Ž��
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

	// ���� ��ġ�� �� �� �ִ� ����, �������� ����
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
	// 1. �������� ���ϴ� DP ���
	vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
	for (vector<int> puddle : puddles)
	{
		DP[puddle[1]][puddle[0]] = -1;
	}

	// 2. DP ����
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			// case : �ܰ� ó��
			if (i == 0 || j == 0)
			{
				DP[i][j] = -1;
				continue;
			}
			// case : ������
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
// Try 3 : DP�� ���� �б��� ��� ���
// ===========================================
int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

	// 1. ������ ���
	for (vector<int> puddle : puddles)
	{
		DP[puddle[1]][puddle[0]] = -1;
	}

	// 2. DP
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			// case : ������
			if (DP[i][j] == -1)
				continue;
			// case : �����
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
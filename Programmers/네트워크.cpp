#include <string>
#include <vector>

using namespace std;

void dfs(int computer, vector<vector<int>>& graph)
{
    graph[computer][computer] = 0;

    for (int i = 0; i < graph[computer].size(); ++i)
    {
        if (graph[computer][i])
        {
            graph[computer][i] = 0;
            graph[i][computer] = 0;

            dfs(i, graph);
        }
    }
}

// Idea : 연결된 Graph 개수 찾기
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); ++i)
    {
        if (computers[i][i])
        {
            answer++;
            dfs(i, computers);
        }
    }

    return answer;
}
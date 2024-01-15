// LeetCode 743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/
#include <vector>
#include <queue>
using namespace std;

// Dijkstra Algo
// - Time Complexity O(NlogN)

/// [TimeError]: 
/// dist를 update하는 경우를 판단하기 전,
/// continue 판단을 따로 해주지 않아도 (조건문 통과하지 못하므로) Time Compolexity가 비슷할 것이라 생각했으나
/// time limit 발생함
/// note: DFS는 flow 분기 처리 반드시 따로 해줘야 할 것처럼 보임

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>> queue;
        vector<vector<pair<int, int>>> graph(n); // <<node, cost>>
        vector<int> dist(n, -1); // init: -1 (infinity)

        // graph
        for (size_t i = 0; i < times.size(); ++i)
        {
            int nodei = times[i][0] - 1;
            int nodej = times[i][1] - 1;
            int time = times[i][2];

            graph[nodei].push_back(make_pair(nodej, time));
        }

        // 0. start node
        dist[k - 1] = 0;
        queue.push(make_pair(k - 1, 0));

        // 1. explore
        while (!queue.empty())
        {
            int curNode = queue.top().first;
            int curDist = queue.top().second;
            queue.pop();

            if (curDist > dist[curNode] && dist[curNode] != -1) continue;
            // case: update dist
            else if (curDist <= dist[curNode] || dist[curNode] == -1)
            {
                dist[curNode] = curDist;
                for (size_t i = 0; i < graph[curNode].size(); ++i)
                {
                    int v = graph[curNode][i].first;
                    int d = graph[curNode][i].second + curDist;
                    if (d < dist[v] || dist[v] == -1)
                    {
                        queue.push(make_pair(v, d));
                        dist[v] = d;
                    }
                }
            }
        }

        // 2. return
        int ret = -1;
        for (int i : dist)
        {
            if (i == -1)
                return -1;
            if (ret < i)
                ret = i;
        }
        return ret;
    }
};
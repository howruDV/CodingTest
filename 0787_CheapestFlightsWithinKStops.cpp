// LeetCode 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include <vector>
#include <queue>
#include <minmax.h>
using namespace std;

// Time Complexity O(E)
class Solution {

private:
    struct cmp
    {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
        {
            if (a.second.first > b.second.first) return true;
            return false;
        }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> queue; // <node, <cost, count> (in expore)
        vector<vector<pair<int, int>>> graph(n); // <<node, cost>>
        vector<int> cost(n, -1); // explore output

        // 1. graph parse
        for (vector<int> i : flights)
            graph[i[0]].push_back(make_pair(i[1], i[2]));

        // 2. start node
        queue.push(make_pair(src, make_pair(0, 0)));
        cost[src] = 0;

        // 3. explore
        while (!queue.empty())
        {
            int curNode = queue.top().first;
            int curCost = queue.top().second.first;
            int curCount = queue.top().second.second;
            queue.pop();

            if (curNode == dst) return curCost;
            else if (curCount > k) continue;

            for (pair<int, int> i : graph[curNode])
            {
                if ((curCost + i.second < cost[i.first] || cost[i.first] == -1) && curCount <= k)
                {
                    queue.push(make_pair(i.first, make_pair(curCost + i.second, curCount + 1)));
                    cost[i.first] = curCost + i.second;
                }
            }
        }

        // 2. return
        int ret = -1;
        return ret;
    }
};
// LeetCode 0973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/
#include <queue>
#include <vector>
using namespace std;

// - Time Complexity O(n log k)
// - Space Complexity O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> retHeap;
        vector<vector<int>> ret;

        // 1. calculate distance & update closest points
        for (vector<int> it : points)
        {
            int dist = (it[0] * it[0] + it[1] * it[1]);

            if (retHeap.size() < k)
                retHeap.emplace(dist, it);
            else if (dist < retHeap.top().first)
            {
                retHeap.pop();
                retHeap.emplace(dist, it);
            }
        }

        // 2. convert to vector
        for (int i = 0; i < k; i++)
        {
            vector<int> vec = retHeap.top().second;
            retHeap.pop();
            ret.push_back(vec);
        }

        return ret;
    }
};
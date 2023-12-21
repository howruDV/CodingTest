// LeetCode 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Time Complexity 
// Space Complexity 
class Solution {
private:
    static bool comp(pair<int, vector<int>>& a, pair<int, vector<int>>& b) {
        return a.second.size() > b.second.size();
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ret;

        // 1. node 연관성 기록
        map<int, vector<int>> nodeMap;
        for (int i = 0; i < edges.size(); ++i)
        {
            if (nodeMap.find(edges[i][0]) != nodeMap.end())
                nodeMap[edges[i][0]].push_back(edges[i][1]);
            else
                nodeMap.insert(edges[i][0], edges[i][1]);

            if (nodeMap.find(edges[i][1]) != nodeMap.end())
                nodeMap[edges[i][1]].push_back(edges[i][0]);
            else
                nodeMap.insert(edges[i][1], edges[i][0]);
        }

        // 1. leaf 찾기: sort
        vector<pair<int, vector<int>>> nodeVec(nodeMap.begin(), nodeMap.end());
        sort(nodeVec.begin(), nodeVec.end(), comp); // 내림차순

        // 2. 쳐나가기
        while (!nodeVec.empty())
        {
            int curNode = (*nodeVec.end()).first;
            vector<int> curNeighbor = (*nodeVec.end()).second;

            if (curNeighbor.size()>1)
            {
                ret.push_back(curNode);
            }
            for (int i = 0; i < curNeighbor.size(); ++i)
            {
                int idx = curNeighbor[i];
                vector<int>::iterator iter = find(nodeVec[idx].second.begin(), nodeVec[idx].second.end(), curNode);
                nodeVec[idx].second.erase(iter);
            }

            // 제거
            nodeVec[nodeVec.size() - 1].second.clear();
            nodeVec.pop_back();

            sort(nodeVec.begin(), nodeVec.end(), comp); // 내림차순
        }

        return ret;
    }
};

/*
int main()
{
    Solution* sol = new Solution;
    vector<vector<int>> vec { {1,0} , {1,2}, {1,4} };
    sol->findMinHeightTrees(4, vec);
    return 0;
}
*/
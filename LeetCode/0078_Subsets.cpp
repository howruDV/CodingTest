// https://leetcode.com/problems/subsets/description/
// LeetCode 0078. Subsets

#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int numIdx, const vector<int>& nums, vector<int>& path)
    {
        if (numIdx >= (int)nums.size())
            return;

        ans.push_back(path);

        for (int i = numIdx + 1; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(i, nums, path);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(-1, nums, path);

        return ans;
    }
};
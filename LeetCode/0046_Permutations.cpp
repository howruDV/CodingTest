// LeetCode 0046. Permutations
// https://leetcode.com/problems/permutations/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& curPath, vector<int> remain)
    {
        if (remain.empty())
        {
            ans.push_back(curPath);
            return;
        }

        for (int i = 0; i < remain.size(); ++i)
        {
            vector<int> newRemain = remain;
            curPath.push_back(remain[i]);   // dfs이므로 curPath를 하나씩 확정지을 수 있음
            newRemain.erase(newRemain.begin() + i);

            dfs(curPath, newRemain);
            curPath.pop_back();             // 그러나 다음 연산을 할 때 반드시 복구시켜야 함
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curPath;
        dfs(curPath, nums);
        return ans;
    }
};
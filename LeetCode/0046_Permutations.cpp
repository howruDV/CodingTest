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
            curPath.push_back(remain[i]);   // dfs�̹Ƿ� curPath�� �ϳ��� Ȯ������ �� ����
            newRemain.erase(newRemain.begin() + i);

            dfs(curPath, newRemain);
            curPath.pop_back();             // �׷��� ���� ������ �� �� �ݵ�� �������Ѿ� ��
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curPath;
        dfs(curPath, nums);
        return ans;
    }
};
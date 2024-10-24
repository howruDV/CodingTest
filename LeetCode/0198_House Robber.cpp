// Leetcode 0198. House Robber
// https://leetcode.com/problems/house-robber/

#include <vector>
#include <minmax.h>
using namespace std;

// Time Complexity O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> DP(nums.size());
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i < 2)
            {
                DP[i] = nums[i];
            }
            else if (i == 2)
            {
                DP[i] = DP[i - 2] + nums[i];
            }
            if (i > 2)
            {
                DP[i] = max(DP[i - 3], DP[i - 2]) + nums[i];
            }

            ans = max(ans, DP[i]);
        }

        return ans;
    }
};
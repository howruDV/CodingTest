// Leetcode 0053. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <minmax.h>
#include <vector>
#include <minmax.h>
using namespace std;

class Solution {
public:
    // =============
    // (1) algorithm
    // =============
    // Time Complexity O(n)
    int maxSubArray(vector<int>& nums) {
        int sub = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (sub <= 0)
            {
                sub = nums[i];
            }
            else
            {
                sub += nums[i];
            }
            
            ans = max(ans, sub);
        }

        return ans;
    }
};
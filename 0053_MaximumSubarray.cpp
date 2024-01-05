// LeetCode 0053. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
#include <vector>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];

        // 1. explore nums
        for (int i = 1; i < nums.size(); ++i)
        {
            // 2. sum current sub array
            if (curSum < 0)
                curSum = nums[i];
            else
                curSum += nums[i];
            
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
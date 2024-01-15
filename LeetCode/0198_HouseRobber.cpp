// LeetCode 0198. House Robber
// https://leetcode.com/problems/house-robber/
#include <vector>
using namespace std;

// -----------------------------
// Tabulation, Bottom-Up
// -----------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> robRec(401, -1);

        for (int i = 0; i <= nums.size()-1; ++i)
        {
            if (i == 0)
                robRec[i] = nums[0];
            else if (i == 1)
                robRec[i] = max(nums[0], nums[1]);
            else
                robRec[i] = max(robRec[i - 2] + nums[i], robRec[i - 1]);
        }

        return robRec[nums.size()-1];
    }
};
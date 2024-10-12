// Leetcode 0136. Single Number
// https://leetcode.com/problems/single-number/
// Time Complexity O(n)
// Space Complexity O(1)

#include <vector>
using namespace std;

// Time Complexity O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};
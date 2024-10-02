// LeetCode 0561. Array Partition
// https://leetcode.com/problems/array-partition/description/

#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(n)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i = i + 2)
        {
            ans += nums[i];
        }

        return ans;
    }
};
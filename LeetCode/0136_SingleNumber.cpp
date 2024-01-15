// LeetCode 0136. Single Number
// https://leetcode.com/problems/single-number/
// - O(n) time complexity
// - O(1) space complexity
#include <vector>
#include <algorithm>
using namespace std;

// ---------------------------------------------
// sort (exeed given time complexity)
// ---------------------------------------------
// - Time Complexity O(n log n)
// - Space Complexity O(1)
class Solution0 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ret{ nums[0] };

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] == nums[i])
                ret.pop_back();
            else
                ret.push_back(nums[i]);
        }

        return ret[0];
    }
};

// ---------------------------------------------
// XOR bit operations
// - XOR same nums return 0
// - therfore, it means 0 ^| single number
// ---------------------------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int it : nums)
            ret ^= it;
        return ret;
    }
};
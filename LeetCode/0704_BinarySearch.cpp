// LeetCode 0704. Binary Search
// https://leetcode.com/problems/binary-search/
// O(log n) time complexity
#include <vector>
using namespace std;

// - Time Complexity O(log n)
// - Space Complexity O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int idx = nums.size() / 2;

        // 1. explore [start, end]
        while (start <= end)
        {
            // case: find target
            if (nums[idx] == target) return idx;
            // case: explore
            else if (nums[idx] < target)
            {
                start = idx + 1;
                idx = start + (end - start + 1) / 2;
            }
            else
            {
                end = idx - 1;
                idx = end - (end - start + 1) / 2;
            }
        }

        return -1;
    }
};
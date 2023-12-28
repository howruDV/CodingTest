// LeetCode 0033. Search in Rotated Sorted Array
// https://leetcode.com/problems/binary-search/
// O(log n) time complexity
#include <vector>
using namespace std;

// ---------------------------------------------
// When split arr in half, one side isn't rotated
// - find next explore range using that arr
// ---------------------------------------------
// - Time Complexity O(log n)
// - Space Complexity O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int idx = nums.size() / 2;

        while (start <= end)
        {
            // case: find target
            if (nums[idx] == target) return idx;
            
            // case: left isn't rotated
            if (nums[start] <= nums[idx])
            {
                if (nums[start] <= target && target < nums[idx])
                {
                    end = idx - 1;
                    idx = end - (end - start + 1) / 2;
                }
                else
                {
                    start = idx + 1;
                    idx = start + (end - start + 1) / 2;
                }
            }

            // case: right isn't rotated
            else
            {
                if (nums[idx] < target && target <= nums[end])
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
        }

        return -1;
    }
};
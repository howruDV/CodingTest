// LeetCode 0075. Sort Colors
// https://leetcode.com/problems/sort-colors/
// - in-place
#include <vector>
using namespace std;

// ---------------------------------------------
// Sorting while Exploring
// - [0, redEnd]            : grouped(0)
// - [redEnd+1, blueHead-1] : unsorted (finally group 1)
// - [blueHead, n-1]        : groupded(1)
// ---------------------------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) return;
        int cur = 0;
        int redEnd = -1;
        int blueHead = nums.size();

        // 1. explore colors
        while (cur < blueHead)
        {
            // case: find 0 (do exchange)
            if (nums[cur] == 0)
            {
                if (cur == redEnd)  // escape exchange
                {
                    cur++;
                    continue;
                }

                swap(nums[cur], nums[++redEnd]);
            }
            // case: find 2 (do exchange)
            else if (nums[cur] == 2)
            {
                if (cur == blueHead) // escape exchange
                {
                    cur--;
                    continue;
                }

                swap(nums[cur], nums[--blueHead]);
            }
            // case: find 1 (nothing)
            else
                cur++;
        }
    }
};
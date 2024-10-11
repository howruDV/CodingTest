// Leetcode 0704. Binary Search
// https://leetcode.com/problems/binary-search/
// Time Complexity O(logn)

#include <vector>
using namespace std;

class Solution {
public:
    // =============
    // (0) recursion
    // =============
    // Time Complexity O(logn)
    int binSearch(vector<int>& nums, int target, int left, int right)
    {
        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return binSearch(nums, target, mid + 1, right);
        else
            return binSearch(nums, target, left, mid - 1);
    }

    int search(vector<int>& nums, int target) {
        return binSearch(nums, target, 0, nums.size() - 1);
    }

    // =============
    // (1) iteration
    // =============
    // Time Complexity O(logn)
    int search_iter(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = nums.size() / 2;

        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
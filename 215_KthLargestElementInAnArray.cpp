// LeetCode 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include <queue>
using namespace std;

// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ret;
        priority_queue<int> heap = priority_queue<int>(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i)
        {
            ret = heap.top();
            heap.pop();
        }

        return ret;
    }
};
// LeetCode 0215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <queue>
using namespace std;

// Time Complexity O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> Heap(nums.begin(), nums.end());

        for (int i = 0; i < k - 1; ++i)
        {
            Heap.pop();
        }

        return Heap.top();
    }
};
// LeetCode 0239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/
#include <vector>
#include <deque>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxIdx = 0;
        deque<int> winChk;
        vector<int> ret;
        
        for (int right = 0; right < nums.size(); ++right)
        {
            // 1. move window: pop values that out of left range of window
            while (!winChk.empty() && winChk.front() <= right - k)
                winChk.pop_front();
            
            // 2. insert: pop same or smaller values compared to new value
            while (!winChk.empty() && nums[winChk.back()] <= nums[right])
                winChk.pop_back();

            winChk.push_back(right);

            if (right >= k - 1)
                ret.push_back(nums[winChk.front()]);
        }

        return ret;
    }
};
// Leetcode 0169. Majority Element
// https://leetcode.com/problems/majority-element/

// Time Complexity O(n)
// Space Complexity O(1)

#include <vector>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == ans)
            {
                count++;
            }
            else
            {
                count--;

                if (count <= 0)
                {
                    ans = nums[i];
                    count = 1;
                }
            }
        }

        return ans;
    }
};
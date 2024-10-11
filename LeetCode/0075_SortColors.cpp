// Leetcode 0075. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
// Space Complexity O(1)
// one pass

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curNode = 0;
        int color0Head = 0;
        int color2Head = nums.size() - 1;

        while (curNode <= color2Head)
        {
            switch (nums[curNode])
            {
            case 0:
            {
                nums[curNode] = nums[color0Head];
                nums[color0Head] = 0;
                color0Head++;
                curNode++;
            }
            break;
            case 1:
            {
                curNode++;
            }
            break;
            case 2:
            {
                nums[curNode] = nums[color2Head];
                nums[color2Head] = 2;
                color2Head--;
            }
            break;
            }
        }
    }
};
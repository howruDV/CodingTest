// LeetCode 0169. Majority Element
// https://leetcode.com/problems/majority-element/description/
#include <vector>
#include <unordered_map>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numRec; // num, count

        for (int it : nums)
        {
            if (++numRec[it] > nums.size() / 2)
                return it;
        }

        return -1;
    }
};
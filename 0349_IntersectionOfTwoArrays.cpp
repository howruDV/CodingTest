// LeetCode 0349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// unordered_map
// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> ret;

        // 1. check first arr
        for (int it : nums1)
        {
            if (hash.find(it) == hash.end())
                hash.emplace(it, 0);
        }

        // 2. check second arr & find intersection
        for (int it : nums2)
        {
            unordered_map<int, int>::iterator find = hash.find(it);
            if (find != hash.end() && find->second == 0)
            {
                ret.push_back(it);
                find->second = -1;
            }
        }
        
        return ret;
    }
};

// exploration
// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                int val = nums1[i];
                ret.push_back(val);
                while (++i < nums1.size() && ++j < nums2.size() && nums1[i] == nums2[j] && nums1[i] == val) {}
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return ret;
    }
};
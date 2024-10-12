// Leetcode 0349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // =============
    // (0) hash(map)
    // =============
    // Time Complexity O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, bool> set1;
        
        for (int i = 0; i < nums1.size(); ++i)
        {
            set1[nums1[i]] = true;
        }

        for (int i = 0; i < nums2.size(); ++i)
        {
            if (set1.find(nums2[i]) != set1.end() && set1[nums2[i]])
            {
                ans.push_back(nums2[i]);
                set1[nums2[i]] = false;
            }
        }

        return ans;
    }
    
    // =============
    // (1) hash (set)
    // =============
    // Time Complexity O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (set1.count(nums2[i]))
            {
                ans.push_back(nums2[i]);
                set1.erase(nums2[i]);
            }
        }

        return ans;
    }
};
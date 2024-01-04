// LeetCode 0455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/description/
#include <vector>
#include <algorithm>
using namespace std;

// - Time Complexity O(n, m)
// - Space Complexity O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;

        int ret = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<int>::iterator sIter = s.begin();

        // 1. explore child
        for (int it : g)
        {
            // 2. find proper size cookie
            while (sIter != s.end() && *sIter < it)
                sIter++;
            if (sIter == s.end())
                break;

            sIter++;
            ret++;
        }

        return ret;
    }
};
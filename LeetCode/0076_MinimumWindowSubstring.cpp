// LeetCode 0076. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/
#include <string>
#include <unordered_map>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(k)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int missing = t.length();
        int left = 0, start = 0, end = INT_MAX;

        // 1. char map setting
        for (int i = 0; i < t.size(); ++i)
            need[t[i]]++;

        // 2. expand window to right
        for (int right = 0; right < s.size(); ++right)
        {
            // 2.1. find char
            if (need[s[right]]-- > 0)
                missing--;

            // 2.2. find all chars
            if (missing == 0)
            {
                // reduce window from left
                while (left < right && need[s[left]] < 0)
                {
                    need[s[left]]++;
                    left++;
                }

                if (right - left <= end - start)
                {
                    start = left;
                    end = right;
                    need[s[left]]++;
                    missing++;
                    left++;
                }
            }
        }

        // case: can't find
        if (end == INT_MAX)
            return "";
        return s.substr(start, end - start + 1);
    }
};
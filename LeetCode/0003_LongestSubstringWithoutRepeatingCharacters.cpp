// Leetcode 0003. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_map>
#include <minmax.h>
using namespace std;

// Time Complexity O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int sub = 0;
        int startPos = 0;
        unordered_map<char, int> alphabetIdx;

        for (int i = 0; i < s.size(); ++i)
        {
            if (alphabetIdx.count(s[i]) == 0 || alphabetIdx[s[i]] < startPos)
            {
                alphabetIdx[s[i]] = i;
                sub++;
            }
            else
            {
                startPos = alphabetIdx[s[i]] + 1;
                alphabetIdx[s[i]] = i;
                sub = i - startPos + 1;
            }

            ans = max(ans, sub);
        }

        return ans;
    }
};
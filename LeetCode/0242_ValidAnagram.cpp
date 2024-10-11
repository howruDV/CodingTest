// Leetcode 0242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // =====================
    // (0) Hash
    // =====================
    // Time Complexity O(n)
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> Hash;

        // 1. 기록
        for (int i = 0; i < s.length(); ++i)
        {
            // s 기록
            if (Hash.find(s[i]) == Hash.end())
            {
                Hash[s[i]] = 1;
            }
            else
            {
                Hash[s[i]]++;
            }

            // t 기록
            if (Hash.find(t[i]) == Hash.end())
            {
                Hash[t[i]] = -1;
            }
            else
            {
                Hash[t[i]]--;
            }
        }

        // 2. anagram check
        for (auto& it : Hash)
        {
            if (it.second != 0)
                return false;
        }
        return true;
    }

    // =====================
    // (1) sort
    // =====================
    // Time Complexity O(nlogn)
    bool isAnagram_sort(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
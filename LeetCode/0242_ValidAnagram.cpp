// LeetCode 0242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/
// - Consider char & Unicode characters
#include <string>
#include <unordered_map>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t || s.length() != t.length()) return false;
        unordered_map<char, int> countMap;

        // 1. count characters
        for (char it : s)
        {
            unordered_map<char, int>::iterator iter = countMap.find(it);
            if (iter != countMap.end())
                iter->second++;
            else
                countMap.insert({ it, 1 });
        }

        // 2. check characters
        for (char it : t)
        {
            unordered_map<char, int>::iterator iter = countMap.find(it);
            if (iter == countMap.end())
                return false;
            else
            {
                iter->second--;
                if (iter->second == 0)
                    countMap.erase(iter);
            }
        }

        if (countMap.empty())
            return true;
        return false;
    }
};
// LeetCode 003. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// - s consists of English letters, digits, symbols and spaces

#include <string>
using namespace std;

// using string fuctions
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    int lengthOfLongestSubstring(string s) {
        int LongestLen = 0;
        int len = 0;
        string subStr = "";

        // 0. explore string
        for (char c : s)
        {
            int findIdx = subStr.find(c);
            if (findIdx != string::npos)
            {
                subStr = subStr.substr(findIdx + 1) + c;

                if (len > LongestLen)
                    LongestLen = len;
                len = subStr.size();
            }
            else
            {
                subStr += c;
                len++;
            }
        }

        // 1. check last length
        if (len > LongestLen)
            LongestLen = len;

        return LongestLen;
    }
};

// not using str functions
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        bool charRecord[256] = { false };
        int LongestLen = 0;
        int len = 0;
        int curSubStrIdx = 0;

        // 0. explore string
        for (int i = 0; i < s.size(); ++i)
        {
            int idx = s[i];
            if (charRecord[idx])
            {
                while (charRecord[idx])
                    charRecord[s[curSubStrIdx++]] = false;
                if (len > LongestLen)
                    LongestLen = len;
                len = i - curSubStrIdx + 1;
            }
            else
                len++;
            charRecord[idx] = true;
        }

        // 1. check last length
        if (len > LongestLen)
            LongestLen = len;

        return LongestLen;
    }
};
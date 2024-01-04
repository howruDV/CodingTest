// LeetCode 0424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/
#include <string>
#include <unordered_map>
#include <minmax.h>
using namespace std;

// - Time Complexity O(nk)
// - Space Complexity O(1)
class Solution0 {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        int remain = k;
        bool bFinish = false;

        // 1. expand window to right
        for (int right = 0; right < s.size(); ++right)
        {
            // 2. find diff char
            if (remain > 0 && s[right] != s[left])
                remain--;
            
            // 3. rescaling window
            while (s[right+1] == s[left])
                right++;

            while (right == s.size() - 1 && left > 0 && remain > 0)
            {
                left--;
                remain--;
                bFinish = true;
            }

            // 4. find current window's end
            if (remain == 0 || right == s.size() - 1)
            {
                maxLen = max(maxLen, right - left + 1);
                remain = k;

                // 4.1. find next window's left
                if (bFinish) break;
                while (left <= right && s[left] == s[left + 1])
                    left++;
                if (left < s.size() - 1) left++;
                right = left;
            }
        }

        if (remain == k && left == 0)
            maxLen = s.size();
        return maxLen;
    }
};

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charRec;
        int left = 0;
        int curMajorCnt = 0;
        int ret = 0;

        for (int right=0; right<s.size(); ++right)
        {
            // 1. count new input char
            // 2. update "curMax" to current majority char's count
            charRec[s[right]]++;
            curMajorCnt = max(curMajorCnt, charRec[s[right]]);

            // 3. when "diff char(not majority char)" exceed "k", move window's left
            if ((right - left + 1) - curMajorCnt > k)
            {
                charRec[s[left]]--;
                left++;
            }

            ret = max(ret, (right - left + 1));
        }
        return ret;
    }
};
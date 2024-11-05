// Leetcode 0424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> Count;
        int ans = 0;
        int left = 0;
        int majorCount = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            Count[s[right]]++;
            majorCount = max(majorCount, Count[s[right]]);

            // 가장 긴 윈도우를 찾고자 함으로, left ptr가 움직이더라도 majorCount는 변경하지 않음 (어짜피 이것보다 작은 값은 답이 아님)
            if ((right - left + 1) - majorCount > k)
            {
                Count[left]--;
                left++;
            }

            ans = max(ans, (right - left + 1));
        }

        return ans;
    }
};
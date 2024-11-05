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

            // ���� �� �����츦 ã���� ������, left ptr�� �����̴��� majorCount�� �������� ���� (��¥�� �̰ͺ��� ���� ���� ���� �ƴ�)
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
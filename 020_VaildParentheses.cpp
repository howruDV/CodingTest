// LeetCode 020. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <vector>
#include <string>
using namespace::std;

// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution {
public:
    bool isValid(string s) {
        vector<char> vecBracket;

        // 0. explor string
        for (size_t i = 0; i < s.length(); ++i)
        {
            // open brackets
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                vecBracket.push_back(s[i]);
            // close brackets
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (vecBracket.empty())
                    return false;

                if (s[i] == ')' && vecBracket.back() == '('
                    || s[i] == ']' && vecBracket.back() == '['
                    || s[i] == '}' && vecBracket.back() == '{')
                    vecBracket.pop_back();
                else
                    return false;
            }
        }

        return vecBracket.empty();
    }
};
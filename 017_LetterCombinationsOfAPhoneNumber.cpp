// LeetCode 017. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
using namespace std;

// - Time Complexity O(m^n)
// - Space Complexity O(n)
class Solution {
public:

    vector<vector<char>> Digit2Char = vector < vector<char>>
    { vector<char>{'a', 'b', 'c'}
        , vector<char>{'d', 'e', 'f'}
        , vector<char>{'g', 'h', 'i'}
        , vector<char>{'j', 'k', 'l'}
        , vector<char>{'m', 'n', 'o'}
        , vector<char>{'p', 'q', 'r', 's'}
        , vector<char>{'t', 'u', 'v'}
        , vector<char>{'w', 'x', 'y', 'z'}
    };

    vector<string> makeChar(vector<string>& v, int digit)
    {
        vector<string> newVec;

        if (v.empty())
        {
            for (int j = 0; j < Digit2Char[digit - 2].size(); ++j)
            {
                string str;
                str += Digit2Char[digit - 2][j];
                newVec.push_back(str);
            }
        }
        else
        {
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = 0; j < Digit2Char[digit - 2].size(); ++j)
                    newVec.push_back(v[i] + Digit2Char[digit - 2][j]);
            }
        }

        v.clear();
        return newVec;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;

        // 0. per digits
        for (int i = 0; i < digits.size(); ++i)
        {
            ret = makeChar(ret, digits[i] - '0');
        }

        return ret;
    }
};
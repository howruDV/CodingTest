// LeetCode 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/

#include <vector>
#include <string>
using namespace std;

// Error: return되는 string 변수는 컴파일러가 string* type으로 선언함, idx 접근 방식이 다름
// - Time Complexity O(n^2)
// - Space Complexity O(n)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        struct charMap { bool bExist; int idx; };
        charMap checkDup['z' - 'a' + 1] = {};
        string strOut = "";

        for (size_t i = 0; i < s.length(); ++i)
        {
            int charIdx = s[i] - 'a';

            // 0. case: first letter
            if (!checkDup[charIdx].bExist)
            {
                checkDup[charIdx].bExist = true;
                checkDup[charIdx].idx = strOut.size();
                strOut += s[i];
            }
            // 1. case: deuplicate letter
            else
            {
                int idx = checkDup[charIdx].idx;

                // 1.0. case: remove front letter
                int a = strOut[idx + 1];
                if (strOut[idx + 1] < s[i])
                {
                    strOut = strOut.substr(0, idx) + strOut.substr(idx + 1);
                    checkDup[charIdx].idx = strOut.size();
                    strOut += s[i];
                }
                // 1.1. case: remove back letter
            }
        }

        string ret = strOut;
        return ret;
    }
};
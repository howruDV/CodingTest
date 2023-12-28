// LeetCode 0393. UTF-8 Validation
// https://leetcode.com/problems/utf-8-validation/
#include <vector>
#include <bitset>
using namespace std;

// ---------------------------------------------
// bitset order: big endian
// ---------------------------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool bNewChar = true;
        int count = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            bitset<8> curBit(data[i]);

            // case: start new char
            // - get byte
            if (bNewChar)
            {
                // case: 1 byte
                if (curBit[7] == 0)
                {
                    bNewChar = true;
                    continue;
                }

                // case: 2~4 byte
                for (int j = 6; j >= 0; --j)
                {
                    if (curBit[j] == 0 && j > 5 || j < 3)
                        return false;

                    if (curBit[j] == 0)
                    {
                        bNewChar = false;
                        count = 7 - j - 1;
                        break;
                    }
                }
            }
            // case: reading char
            // - check format
            else
            {
                if (--count == 0)
                    bNewChar = true;
                if (curBit[7] != 1 || curBit[6] != 0 || count < 0)
                    return false;
            }
        }

        if (count > 0)
            return false;
        return true;
    }
};
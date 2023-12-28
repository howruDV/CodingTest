// LeetCode 0371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/
#include <math.h>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    int getSum(int a, int b) {
        int ret = 0;
        int sign = 0;
        int carry = 0;
        int i = 0;

        // 1. decide sign
        if (a >> 31 != b >> 31)
            sign = 0;
        else
            sign = (a >> 31) << 31;

        // 2. add bit from back
        while (i < 32 && (abs(a) > 0 || abs(b) > 0 || carry))
        {
            int cur = a & 1 ^ b & 1;
            cur ^= carry;
            if (((a & 1) == (b & 1) && (a & 1) == 1) || (carry == 1 && cur == 0))
                carry = 1;
            else
                carry = 0;

            cur = cur << i++;
            ret |= cur;
            a = a >> 1;
            b = b >> 1;
        }
        ret |= sign;

        return ret;
    }
};

// - Time Complexity O(1)
// - Space Complexity O(1)
class Solution1 {
public:
    int getSum(int a, int b) {
        while (b != 0)
        {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};
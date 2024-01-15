// LeetCode 0461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/
#include <bitset>
using namespace std;

// ---------------------------------------------
// sort (exeed given time complexity)
// ---------------------------------------------
// - Time Complexity O(m log m)
// - Space Complexity O(1)
class Solution0 {
public:
    int hammingDistance(int x, int y) {
        int cal = x ^ y;
        int ret = 0;

        while (cal > 0)
        {
            int i = 0;
            for (; pow(2, i) <= cal; i++) {}
            cal -= pow(2, i - 1);

            ret++;
        }

        return ret;
    }
};

// ---------------------------------------------
// bit operation
// ---------------------------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;

        while (x > 0 || y > 0)
        {
            if ((x & 1) != (y & 1))
                ret++;
            x = x >> 1;
            y = y >> 1;
        }

        return ret;
    }
};

// ---------------------------------------------
// bitset
// ---------------------------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        string bitX = bitset<32>(x).to_string();
        string bitY = bitset<32>(y).to_string();

        for (int i = 0; i < 32; i++)
        {
            if (bitX[i] != bitY[i])
                ret++;
        }

        return ret;
    }
};
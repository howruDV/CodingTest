// Leetcode 0461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/

#include <bitset>
using namespace std;

class Solution {
public:
    // ================
    // (0) bitset
    // ================
    int hammingDistance(int x, int y) {
        bitset<32> bit(x^y);
        return (int)bit.count();
    }
    
    // ================
    // (1) bit operator
    // ================
    int hammingDistance_bitop(int x, int y) {
        int ans = 0;
        x = x ^ y;

        while (x > 0)
        {
            if (x & 0b0001)
            {
                ans++;
            }

            x = x >> 1;
        }

        return ans;
    }
};
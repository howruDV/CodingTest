// LeetCode 0191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
#include <cstdint>
#include <bitset>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        string bitN = bitset<32>(n).to_string();

        for (char c : bitN)
        {
            if (c == '1')
                ret++;
        }
        return ret;
    }
};

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};
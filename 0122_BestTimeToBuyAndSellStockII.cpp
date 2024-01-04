// LeetCode 0076. Minimum Window Substring
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <vector>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;

        for (int i=1; i<prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i-1];
        }

        return ret;
    }
};
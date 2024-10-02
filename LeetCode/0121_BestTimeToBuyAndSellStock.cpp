// LeetCode 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <vector>
#include <minmax.h>
using namespace std;

// Time Complexity : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = prices[0];

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }

            ans = max(ans, prices[i] - min);
        }

        return ans;
    }
};
// LeetCode 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <vector>
using namespace std;

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int maxIdx = 0;
        int minIdx = 0;
        int maxPrice = 0;
        unsigned int minPrice = -1;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] > maxPrice)
            {
                maxIdx = i;
                maxPrice = prices[i];

                if (minIdx < maxIdx)
                {
                    int updateProfit = prices[maxIdx] - prices[minIdx];
                    if (updateProfit > maxProfit)
                        maxProfit = updateProfit;
                }
            }
            if (prices[i] < minPrice)
            {
                minIdx = i;
                minPrice = prices[i];

                if (minIdx < maxIdx)
                {
                    int updateProfit = prices[maxIdx] - prices[minIdx];
                    if (updateProfit > maxProfit)
                        maxProfit = updateProfit;
                }
                else
                {
                    maxIdx = i;
                    maxPrice = prices[i];
                }
            }
        }

        return maxProfit;
    }
};
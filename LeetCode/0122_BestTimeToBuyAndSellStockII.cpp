// Leetcode 0122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <vector>
using namespace std;

class Solution {
public:
    // ===========================
    // (0) 변곡점 : 구간 분할, 누적
    // ===========================
    // Time Complexity O(n)
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curMin = prices[0];
        int curMax = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            // 같은 날에 다시 주식을 살 수 있으므로, 변곡점에서 구간을 분리해 누적 가능 (그리디) 
            if (prices[i] < curMax)
            {
                ans += (curMax > curMin) ? (curMax - curMin) : 0;
                curMin = prices[i];
                curMax = prices[i];
            }
            else if (prices[i] > curMax)
            {
                curMax = prices[i];
            }
        }

        ans += (curMax > curMin) ? (curMax - curMin) : 0;
        return ans;
    }

    // ==================
    // (1) 매일 이익 계산 : 어짜피 모든 구간이 누적되므로 구간을 "매일" 쪼개 매일 가능한 이익 계산해도 같음
    // ==================
    // Time Complexity O(n)
    int maxProfit_daily(vector<int>& prices) {
        int ans = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                ans += prices[i] - prices[i - 1];
            }
        }

        return ans;
    }
};
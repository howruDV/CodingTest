// Leetcode 0122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <vector>
using namespace std;

class Solution {
public:
    // ===========================
    // (0) ������ : ���� ����, ����
    // ===========================
    // Time Complexity O(n)
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curMin = prices[0];
        int curMax = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            // ���� ���� �ٽ� �ֽ��� �� �� �����Ƿ�, ���������� ������ �и��� ���� ���� (�׸���) 
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
    // (1) ���� ���� ��� : ��¥�� ��� ������ �����ǹǷ� ������ "����" �ɰ� ���� ������ ���� ����ص� ����
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
// Leetcode 0070. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int DP[46];
    
    // ===================
    // (0) Memorization
    // ===================
    // Time Complexity O(n)
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (DP[n] != 0) return DP[n];

        DP[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return DP[n];
    }
    
    // ===================
    // (1) Tabulation
    // ===================
    // Time Complexity O(n)
    int climbStairs_Tabulation(int n) {
        DP[1] = 1;
        DP[2] = 2;
        
        for (int i = 3; i <= n; ++i)
        {
            DP[n] = DP[n - 1] + DP[n - 2];
        }

        return DP[n];
    }
};
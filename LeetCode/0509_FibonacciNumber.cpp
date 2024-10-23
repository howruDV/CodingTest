// Leetcode 0509. Fibonacci Number
//https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int DP[31];

    // =================
    // (0) Memorization
    // =================
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (DP[n] != 0) return DP[n];

        DP[n] = fib(n - 1) + fib(n - 2);
        return DP[n];
    }
    
    // =================
    // (1) Tabulation
    // =================
    int fib_Tabulation(int n) {
        DP[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            DP[i] = DP[i - 1] + DP[i - 2];
        }

        return DP[n];
    }
};
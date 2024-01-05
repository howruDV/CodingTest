// LeetCode 0169. Majority Element
// https://leetcode.com/problems/majority-element/description/
#include <vector>
using namespace std;

// -----------------------------
// recursion
// -----------------------------
// - Time Complexity O(2^n)
// - Space Complexity O(2^n)
class Solution0 {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// -----------------------------
// Tabluation, Bottom-Up
// -----------------------------
// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution1 {
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        
        for (int i = 0; i <= n; ++i)
        {
            if (i <= 1)
                dp[i] = i;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// -----------------------------
// Memoization, Top-Down
// -----------------------------
// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution2 {
private:
    int dp[31] = { 0, };

public:
    int fib(int n) {
        if (n <= 1)
        {
            dp[n] = n;
            return n;
        }

        if (dp[n] != 0)
            return dp[n];
        
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};
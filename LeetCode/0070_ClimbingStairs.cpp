// LeetCode 0070. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

// -----------------------------
// Memoization, Top-Down
// -----------------------------
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
private:
    int stepRec[46] = { 0, };

public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        if (stepRec[n])
            return stepRec[n];
        
        stepRec[n] = climbStairs(n - 2) + climbStairs(n - 1);
        return stepRec[n];
    }
};
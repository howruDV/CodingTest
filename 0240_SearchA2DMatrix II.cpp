// LeetCode 0240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <vector>
using namespace std;

// ------------------------------------
// explore: start from matrix(height:0)'s biggest num
// - when target is smaller than num, reduce width(col)
// - when target is bigger than num, increase height(row)
// ------------------------------------
// - Time Complexity O(col + row)
// - Space Complexity O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size() - 1;
        int row = 0;

        while (col >= 0 && row < matrix.size())
        {
            if (matrix[row][col] == target)
                return true;
            
            matrix[row][col] > target ? col-- : row++;
        }

        return false;
    }
};
// LeetCode 0167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// - O(1) space complexitiy
#include <vector>
using namespace std;

// - Time Complexity O(n^2)
// - Space Complexity O(1)
class Solution0 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int prevEnd = numbers.size() - 1;

        for (int i = 0; i < numbers.size(); ++i)
        {
            if (i > 1 && numbers[i] == numbers[i - 1] && numbers[i - 1] == numbers[i - 2])
                continue;

            for (int j = prevEnd; j>i; --j)
            {
                if (numbers[i] + numbers[j] == target)
                    return { i+1, j+1 };
                else if (numbers[i] + numbers[j] > target)
                    prevEnd = j;
            }
        }

        return {};
    }
};

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()- 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
                return { i + 1, j + 1 };
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }

        return {};
    }
};
// LeetCode 0771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

#include <string>
#include <unordered_map>
using namespace std;

// Time Complexity O(n)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_map<char, int> stoneCount;

        for (int i = 0; i < stones.size(); ++i)
        {
            if (stoneCount.find(stones[i]) != stoneCount.end())
            {
                stoneCount[stones[i]]++;
            }
            else
            {
                stoneCount[stones[i]] = 1;
            }
        }

        for (int i = 0; i < jewels.size(); ++i)
        {
            if (stoneCount.find(jewels[i]) != stoneCount.end())
            {
                ans += stoneCount[jewels[i]];
            }
        }

        return ans;
    }
};
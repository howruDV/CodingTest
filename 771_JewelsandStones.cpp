// LeetCode 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

#include <string>
#include <map>
using namespace std;

// map ver
// - Time Complexity O(nlogn)
// - Space Complexity O(n)
class Solution0 {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        map<char, int> mapJewel;

        // 0. create jewel map
        for (int i = 0; i < jewels.size(); ++i)
            mapJewel.insert({ (char)jewels[i], 0 });

        // 1. explore stones
        map<char, int>::iterator iter;
        for (int i = 0; i < stones.size(); ++i)
        {
            iter = mapJewel.find(stones[i]);
            if (iter != mapJewel.end())
                iter->second++;
        }

        // 2. count jewels
        for (iter = mapJewel.begin(); iter != mapJewel.end(); ++iter)
            count += iter->second;

        return count;
    }
};

// explore ver
// - Time Complexity O(n^2)
// - Space Complexity O(1)
class Solution0 {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for (int i = 0; i < jewels.size(); ++i)
        {
            for (int j = 0; j < stones.size(); ++j)
            {
                if (stones[j] == jewels[i])
                    count++;
            }
        }

        return count;
    }
};
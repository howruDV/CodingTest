// LeetCode 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/

#include <vector>
#include <deque>
using namespace std;

// Explore Every Day: Time Limite Error
// - Time Complexity O(n^2)
// - Space Complexity O(n)
class Solution0 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vecOut;
        vector<int>::iterator iterCur = temperatures.begin();

        for (int i = 0; i < temperatures.size(); ++i)
        {
            for (int j = i; j < temperatures.size(); ++j)
            {
                if ((*iterCur) < temperatures[j])
                {
                    vecOut.push_back(j - i);
                    break;
                }
                else if (j == temperatures.size() - 1)
                {
                    vecOut.push_back(0);
                }
            }

            ++iterCur;
        }

        return vecOut;
    }
};

// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vecOut;
        vector<int> vecIdxRecord;   // record unupdated index 
        vecOut.resize(temperatures.size());
        vecIdxRecord.push_back(0);

        // 0. explore vector
        for (int i = 1; i < temperatures.size(); ++i)
        {
            int lastRecIdx = vecIdxRecord.back();

            // 1. update unupdated node
            while (temperatures[i] > temperatures[lastRecIdx])
            {
                vecOut[lastRecIdx] = i - lastRecIdx;

                vecIdxRecord.pop_back();
                if (!vecIdxRecord.empty())
                {
                    lastRecIdx = vecIdxRecord.back();
                }
                else
                    break;
            }

            vecIdxRecord.push_back(i);
        }

        return vecOut;
    }
};

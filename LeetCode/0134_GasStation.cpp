// LeetCode 0134. Gas Station
// https://leetcode.com/problems/gas-station/
#include <vector>
using namespace std;

// - Time Complexity O(n^2)
// - Space Complexity O(n)
class Solution0 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> surplusGas;

        // 1. get surplus Gas
        for (int i = 0; i < gas.size(); ++i)
            surplusGas.push_back(gas[i] - cost[i]);

        // 2. find start point
        for (int i = 0; i < surplusGas.size(); ++i)
        {
            if (surplusGas[i] < 0 || (surplusGas[i] == 0 && gas.size() != 1))
                continue;

            int nextStation = (i + 1) % gas.size();
            int remainGas = surplusGas[i];

            // 3. check circuit
            while (nextStation != i || gas.size() == 1)
            {
                remainGas += surplusGas[nextStation];
                if (remainGas < 0)
                    break;

                nextStation = (nextStation + 1) % gas.size();
                if (nextStation == i)
                    return i;
            }
        }

        return -1;
    }
};

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int curGas = 0;
        int startIdx = 0;

        // 1. calculate surplus gas
        for (int i = 0; i < gas.size(); ++i)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            curGas += gas[i] - cost[i];

            // case: sum of current travel becomes negative
            if (curGas < 0)
            {
                curGas = 0;
                startIdx = (i + 1 != gas.size()) ? i + 1 : -1;
            }
        }
        return (totalGas >= totalCost) ? startIdx : -1;
    }
};
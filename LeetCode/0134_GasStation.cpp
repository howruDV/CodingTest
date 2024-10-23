// Leetcode 0134. Gas Station
// https://leetcode.com/problems/gas-station/

#include <vector>
using namespace std;

class Solution {
public:
	// ====================
	// (0) 최저 변곡점 찾기
	// ====================
	// Time Complexity O(1)
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int costSum = 0;
		int costMinSum = INT_MAX;
		int costMinidx = 0;

		for (int i = 0; i < gas.size(); ++i)
		{
			int costRemain = gas[i] - cost[i];
			costSum += costRemain;

			if (costSum < costMinSum)
			{
				costMinSum = costSum;
				costMinidx = i;
			}
		}

		if (costSum < 0)
			return -1;

		if (++costMinidx >= gas.size())
		{
			costMinidx -= gas.size();
		}

		return costMinidx;
	}

	// ====================
	// (1) 불가능한 점 제외하기
	// ====================
	// Time Complexity O(1)
	int canCompleteCircuit_exclude(vector<int>& gas, vector<int>& cost) {
		int costSum = 0;
		int ans = 0;
		int curSum = 0;

		for (int i = 0; i < gas.size(); ++i)
		{
			costSum += gas[i] - cost[i];
			curSum += gas[i] - cost[i];

			if (curSum < 0)
			{
				curSum = 0;
				ans = i + 1;
			}
		}

		if (costSum < 0)
			return -1;

		ans = (ans >= gas.size()) ? (ans - gas.size()) : ans;
		return ans;
	}
};
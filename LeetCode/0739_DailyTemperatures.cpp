// LeetCode 0739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <vector>
#include <stack>
using namespace std;

// Time Complexity O(n)
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> ans(temperatures.size(), 0);
		stack<int> DescTempIdx;

		for (int i = 0; i < temperatures.size(); ++i)
		{
			// ���� ��ϵ麸�� ������ ���, �׷��� ���� ������ ���� ����
			while (!DescTempIdx.empty() && temperatures[i] > temperatures[DescTempIdx.top()])
			{
				ans[DescTempIdx.top()] = i - DescTempIdx.top();
				DescTempIdx.pop();
			}

			DescTempIdx.push(i);
		}

		return ans;
	}
};
// LeetCode 0148. Sort List
// https://leetcode.com/problems/merge-intervals/
#include <vector>
#include <algorithm>
using namespace std;

// Using Default Sort Algo.
// Time Complexity O(nlog(n))
// Space Complexity O(n)
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ret = { intervals[0] };

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][0] <= ret.back()[1])
			{
				if (intervals[i][1] > ret.back()[1])
					ret.back()[1] = intervals[i][1];
			}
			else if (intervals[i][0] > ret.back()[1])
			{
				ret.push_back(intervals[i]);
			}
		}
	}
};
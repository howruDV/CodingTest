// Leetcode 0973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	// ===========
	// (0) heap
	// ===========
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Dist; // dist, idx

		// 1. dist 기록
		for (int i = 0; i < points.size(); ++i)
		{
			int distPow = points[i][0] * points[i][0] + points[i][1] * points[i][1];
			Dist.push({ distPow, i });
		}

		// 2. find K closest
		vector<vector<int>> ans;

		for (int i = 0; i < k; ++i)
		{
			ans.push_back(points[Dist.top().second]);
			Dist.pop();
		}

		return ans;
	}

	// ===========
	// (0) heap
	// ===========
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<pair<int, int>> Dist; // dist, idx

		// 1. dist 기록
		for (int i = 0; i < points.size(); ++i)
		{
			int distPow = points[i][0] * points[i][0] + points[i][1] * points[i][1];
			Dist.push_back({ distPow, i });
		}

		// 2. find K closest
		sort(Dist.begin(), Dist.end());
		vector<vector<int>> ans;

		for (int i = 0; i < k; ++i)
		{
			ans.push_back(points[Dist[i].second]);
		}

		return ans;
	}
};
// Leetcode 0743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		int ans = -1;
		vector<int> Weight(n + 1, -1);
		vector<vector<pair<int, int>>> EdgeTo(n + 1);
		// priority queue : 최우선순위 업데이트 값부터 확인해 ㅡ 쓸모 없는 연산을 줄이려는 목적
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Queue;

		// create EdgeTo
		for (int i = 0; i < times.size(); ++i)
		{
			vector<int>& curNetwork = times[i];
			EdgeTo[curNetwork[0]].push_back({ curNetwork[1], curNetwork[2] });
		}

		// 확산 : 현재노드로부터 진행가능한 간선의 가중치값 업데이트 (새로 업데이트되는 경우 다시 검사)
		Weight[k] = 0;
		Queue.push({ 0, k });

		while (!Queue.empty())
		{
			int NodeWeight = Queue.top().first;
			int NodeIdx = Queue.top().second;
			Queue.pop();

			// 최소 Weight가 이미 업데이트 됐다면
			if (NodeWeight > Weight[NodeIdx])
				continue;

			for (int i = 0; i < EdgeTo[NodeIdx].size(); ++i)
			{
				int NodeTo = EdgeTo[NodeIdx][i].first;
				int NewWeight = EdgeTo[NodeIdx][i].second + NodeWeight;

				// Weight가 더 적은 경우 가중치 업데이트
				if (Weight[NodeTo] < 0 || NewWeight < Weight[NodeTo])
				{
					Weight[NodeTo] = NewWeight;
					Queue.push({ NewWeight, NodeTo });
				}
			}
		}

		for (int i = 1; i < Weight.size(); ++i)
		{
			if (Weight[i] < 0)
				return -1;

			ans = max(ans, Weight[i]);
		}

		return ans;
	}
};
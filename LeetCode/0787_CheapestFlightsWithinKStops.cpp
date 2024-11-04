// Leetcode 0787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <vector>
#include <queue>
using namespace std;

// main Idea : dijkstra �˰����� Ȱ��
// (queue�� ������ ��츦 ��� �־� ó���ϴ� ��)
class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		// 0. Graph ����
		vector<vector<pair<int, int>>> Graph(n); // <to, price> 
		vector<int> Dist(n, INT_MAX);

		for (vector<int> flight : flights)
		{
			int from = flight[0];
			int to = flight[1];
			int price = flight[2];
			Graph[from].push_back({ to, price });
		}

		// 1. Dijkstra
		priority_queue<vector<int>, vector<vector<int>>, greater<>> q; // <price, idx, k>
		q.push(vector<int>{0, src, -1});
		Dist[src] = 0;

		while (!q.empty())
		{
			int price = q.top()[0];
			int idx = q.top()[1];
			int stop = q.top()[2];
			q.pop();

			if (idx == dst)
				return price;
			if (stop > k || stop > Dist[idx])
				continue;

			Dist[idx] = stop;

			for (pair<int, int> newPath : Graph[idx])
			{
				int newIdx = newPath.first;
				int newPrice = price + newPath.second;
				q.push({ newPrice, newIdx, stop + 1 });
			}
		}

		return -1;
	}
};
// LeetCode 0077. Combinations
// https://leetcode.com/problems/combinations/

#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;

	void dfs(vector<int>& curComb, const int& range, const int& maxCount)
	{
		if (curComb.size() == maxCount)
		{
			ans.push_back(curComb);
			return;
		}

		int i = curComb.empty() ? 0 : curComb.back();
		for (; i < range; ++i)
		{
			curComb.push_back(i + 1);

			dfs(curComb, range, maxCount);

			curComb.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int> curComb;

		dfs(curComb, n, k);
		return ans;
	}
};
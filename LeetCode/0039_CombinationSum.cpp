// Leetcode 0039. Combination Sum
// https://leetcode.com/problems/combination-sum/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<vector<int>>> DP(target + 1);
		DP[0] = { {} };

		// 각 후보에 대해
		for (int candNum : candidates)
		{
			// target 하위 수 구성
			for (int subTarget = candNum; subTarget <= target; ++subTarget)
			{
				for (vector<int> comb : DP[subTarget - candNum])
				{
					comb.push_back(candNum);
					DP[subTarget].push_back(comb);
				}
			}
		}

		return DP[target];
	}
};

class Solution {
public:
	vector<vector<int>> ans;

	void dfs(int remainSum, int candIdx, const vector<int>& candidates, vector<int>& path)
	{
		if (remainSum <= 0)
			return;

		for (int i = candIdx; i < candidates.size(); ++i)
		{
			path.push_back(candidates[i]);

			if (remainSum - candidates[i] > 0)
			{
				dfs(remainSum - candidates[i], i, candidates, path);
			}
			else if (remainSum - candidates[i] == 0)
			{
				ans.push_back(path);
			}

			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> path;
		dfs(target, 0, candidates, path);

		return ans;
	}
};
// LeetCode 0001. Two Sum
// https://leetcode.com/problems/two-sum/
// - Time Complexity : less than O(n2)

#include <vector>
#include <unordered_map>
using namespace std;

// - Time Complexity O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> IdxsByValue; // Value, Idxs

		// 0. create map
		for (int i = 0; i < nums.size(); ++i)
		{
			IdxsByValue[nums[i]] = i;
		}

		// 1. find twoSum
		for (int i = 0; i < nums.size(); ++i)
		{
			int FindNum = target - nums[i];

			if (IdxsByValue.find(FindNum) != IdxsByValue.end())
			{
				// case : same nums
				if (FindNum == nums[i])
				{
					if (IdxsByValue[FindNum] != i)
						return vector<int>{i, IdxsByValue[FindNum]};
				}
				// case : other nums
				else
				{
					return vector<int>{i, IdxsByValue[FindNum]};
				}
			}
		}

		return vector<int>(2);
	}
};
// LeetCode 0015. 3Sum
// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(n^2)
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int twoSum = -nums[i];
			int leftPtr = i + 1;
			int rightPtr = nums.size() - 1;

			while (leftPtr < rightPtr)
			{
				if (nums[leftPtr] + nums[rightPtr] == twoSum)
				{
					ans.push_back(vector<int>{nums[i], nums[leftPtr], nums[rightPtr]});

					leftPtr++;
					rightPtr--;

					while (leftPtr < nums.size() && nums[leftPtr] == nums[leftPtr - 1])
					{
						leftPtr++;
					}
					while (rightPtr > -1 && nums[rightPtr] == nums[rightPtr + 1])
					{
						rightPtr--;
					}
				}
				else if (nums[leftPtr] + nums[rightPtr] < twoSum)
				{
					leftPtr++;
				}
				else
				{
					rightPtr--;
				}
			}
		}

		return ans;
	}
};
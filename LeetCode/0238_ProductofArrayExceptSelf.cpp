// LeetCode 0238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/description/
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(n)
class Solution {
public:
	// ===========================
	// (1) Space Complexity : O(n)
	// ===========================
	vector<int> productExceptSelf0(vector<int>& nums) {
		vector<int> ans(nums.size());
		vector<int> left(nums.size());
		vector<int> right(nums.size());

		int maxIdx = nums.size() - 1;
		left[0] = nums[0];
		right[maxIdx] = nums[maxIdx];

		for (int i = 1; i < nums.size(); ++i)
		{
			left[i] = left[i - 1] * nums[i];
			right[maxIdx - i] = right[maxIdx - i + 1] * nums[maxIdx - i];
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			int leftProduct = (i == 0) ? 1 : left[i - 1];
			int rightProduct = (i == maxIdx) ? 1 : right[i + 1];
			ans[i] = leftProduct * rightProduct;
		}

		return ans;
	}

	// ===========================
	// (2) Space Complexity : O(1)
	// ===========================
	vector<int> productExceptSelf1(vector<int>& nums) {
		vector<int> ans(nums.size());
		int maxIdx = nums.size() - 1;

		// 1. product from left
		ans[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			ans[i] = ans[i - 1] * nums[i];
		}

		// 2. product from right
		for (int i = maxIdx - 1; i >= 0; --i)
		{
			nums[i] *= nums[i + 1];
		}

		// 3. calc
		for (int i = maxIdx; i >= 0; --i)
		{
			int leftProduct = (i == 0) ? 1 : ans[i - 1];
			int rightProduct = (i == maxIdx) ? 1 : nums[i + 1];
			ans[i] = leftProduct * rightProduct;
		}

		return ans;
	}
};
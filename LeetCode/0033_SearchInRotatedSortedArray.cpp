// Leetcode 0033. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Time Complexity O(logn)

#include <vector>
using namespace std;

// Time Complexity O(logn)
class Solution {
public:
	int binSearch(const vector<int>& nums, const int& target, int left, int right)
	{
		if (left > right)
			return -1;

		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
			return mid;

		// 회전되지 않은 구간을 찾아 그쪽에 포함되는지 확인한다
		// 아니라면 회전된 구간으로 넘긴다

		// 오른쪽이 회전되지 않았다면
		if (mid + 1 <= right && nums[mid + 1] <= nums[right])
		{
			if (nums[mid + 1] <= target && target <= nums[right])
				return binSearch(nums, target, mid + 1, right);
			else
				return binSearch(nums, target, left, mid - 1);
		}
		// 왼쪽이 회전되지 않았다면
		else if (mid - 1 >= left && nums[mid - 1] >= nums[left])
		{
			if (nums[left] <= target && target <= nums[mid - 1])
				return binSearch(nums, target, left, mid - 1);
			else
				return binSearch(nums, target, mid + 1, right);
		}

		return -1;
	}

	int search(vector<int>& nums, int target) {
		return binSearch(nums, target, 0, nums.size() - 1);
	}
};
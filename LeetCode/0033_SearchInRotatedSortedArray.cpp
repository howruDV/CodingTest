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

		// ȸ������ ���� ������ ã�� ���ʿ� ���ԵǴ��� Ȯ���Ѵ�
		// �ƴ϶�� ȸ���� �������� �ѱ��

		// �������� ȸ������ �ʾҴٸ�
		if (mid + 1 <= right && nums[mid + 1] <= nums[right])
		{
			if (nums[mid + 1] <= target && target <= nums[right])
				return binSearch(nums, target, mid + 1, right);
			else
				return binSearch(nums, target, left, mid - 1);
		}
		// ������ ȸ������ �ʾҴٸ�
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
// Leetcode 0239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

#include <vector>
#include <deque>
#include <queue>
using namespace std;

class Solution {
public:
	// ============================
	// Try 1 (Time Limit Error)
	// ============================
	// Idea : max���� ������ �ִٰ�, max ���� ���������� ������ max �� �ٽ� ã��
	vector<int> maxSlidingWindow_Try1(vector<int>& nums, int k) {
		vector<int> ans;
		int windowMaxIdx = 0;
		int right = 0;

		// move window
		for (int left = 0; left <= nums.size() - k; ++left)
		{
			// find max
			if (windowMaxIdx < left || left == 0)
			{
				windowMaxIdx = left;

				for (right = left + 1; right - left < k; ++right)
				{
					if (nums[right] > nums[windowMaxIdx])
					{
						windowMaxIdx = right;
					}
				}
			}
			// know max idx
			else
			{
				if (nums[right] > nums[windowMaxIdx])
				{
					windowMaxIdx = right;
				}

				right++;
			}
			
			ans.push_back(nums[windowMaxIdx]);
		}

		return ans;
	}

	// ============================
	// Try 2
	// ============================
	// Idea : max ���� ���������� �� �ٷ� ���ο� max�� ã�� �� �ִ� ��� ��� �ʿ�
	// ���� window ������ ���� �����ϴ� �����̳ʸ� �����,
	// ���� ������ ������ ���� ���� ��� �����
	// max�� ���� ������ �� �� �ֵ��� �����ϱ�
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> window;

		for (int right = 0; right < nums.size(); ++right)
		{
			// 1. window ����
			if (!window.empty() && window.front() <= right - k)
			{
				window.pop_front();
			}

			// 2. ���� �߰��ϴ� ������ ���� �� ����
			while (!window.empty() && nums[window.back()] <= nums[right])
			{
				window.pop_back();
			}

			// 3. window �߰�
			window.push_back(right);
			
			if (right >= k - 1)
			{
				ans.push_back(nums[window.front()]);
			}
		}

		return ans;
	}
	
	// ============================
	// Try 3
	// ============================
	// Idea : Priority Queue ����ؼ� ���� ���� ū �� ������ ã��
	vector<int> maxSlidingWindow_pq(vector<int>& nums, int k) {
		vector<int> ans;
		priority_queue<pair<int, int>> window; // num, idx

		for (int right = 0; right < nums.size(); ++right)
		{
			// 1. max �� idx Ȯ��
			while (!window.empty() && window.top().second <= right - k)
			{
				window.pop();
			}

			// 2. window �߰�
			window.push({ nums[right], right });

			if (right >= k - 1)
			{
				ans.push_back(window.top().first);
			}
		}

		return ans;
	}
};
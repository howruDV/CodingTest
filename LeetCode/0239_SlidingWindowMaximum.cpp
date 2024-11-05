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
	// Idea : max값을 가지고 있다가, max 값이 빠져나가는 순간만 max 값 다시 찾기
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
	// Idea : max 값이 빠져나갔을 때 바로 새로운 max를 찾을 수 있는 방법 고안 필요
	// 현재 window 내부의 값을 저장하는 컨테이너를 만들어,
	// 새로 들어오는 값보다 작은 값은 모두 지우며
	// max가 가장 앞으로 올 수 있도록 관리하기
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> window;

		for (int right = 0; right < nums.size(); ++right)
		{
			// 1. window 해제
			if (!window.empty() && window.front() <= right - k)
			{
				window.pop_front();
			}

			// 2. 새로 추가하는 값보다 작은 값 해제
			while (!window.empty() && nums[window.back()] <= nums[right])
			{
				window.pop_back();
			}

			// 3. window 추가
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
	// Idea : Priority Queue 사용해서 현재 가장 큰 값 빠르게 찾기
	vector<int> maxSlidingWindow_pq(vector<int>& nums, int k) {
		vector<int> ans;
		priority_queue<pair<int, int>> window; // num, idx

		for (int right = 0; right < nums.size(); ++right)
		{
			// 1. max 값 idx 확인
			while (!window.empty() && window.top().second <= right - k)
			{
				window.pop();
			}

			// 2. window 추가
			window.push({ nums[right], right });

			if (right >= k - 1)
			{
				ans.push_back(window.top().first);
			}
		}

		return ans;
	}
};
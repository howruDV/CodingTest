// LeetCode 0042. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	// ======================
	// 00 : ������ ����
	// ���� ��ȭ�� ����ϴ� ������ �״ٰ�, ���̰� �����ϴ� �������� ������ ������ Ǯ�� ���� �� �ִ� �� ���� ����Ѵ�
	// ======================
	// Time Complexity : O(n)
	int trap0(vector<int>& height) {
		int ans = 0;
		deque<pair<int, int>> prevHeight; // stack(height, idx)

		for (int i = 0; i < height.size(); ++i)
		{
			// 0. Create Height Stack
			if (prevHeight.empty())
			{
				if (height[i] != 0)
				{
					prevHeight.push_back(make_pair(height[i], i));
				}

				continue;
			}

			// 1. Trapping
			while (height[i] > prevHeight.back().first && prevHeight.size() != 1)
			{
				int lastIdx = prevHeight.size() - 1;
				int h = min(prevHeight[lastIdx - 1].first - prevHeight[lastIdx].first, height[i] - prevHeight[lastIdx].first);
				int w = i - prevHeight[lastIdx - 1].second - 1;
				ans += h * w;

				prevHeight.pop_back();
			}

			// 2. Manage Height Stack
			if (height[i] == prevHeight.back().first)
			{
				prevHeight.back().second = i;
			}
			else if (height[i] < prevHeight.back().first)
			{
				prevHeight.push_back(make_pair(height[i], i));
			}
			else if (height[i] > prevHeight.front().first)
			{
				prevHeight.clear();
				prevHeight.push_back(make_pair(height[i], i));
			}
		}

		return ans;
	}

	// ======================
	// 01 : �糡���� Ž���� ������Ű��
	// ������ �� ���� �����, ���� �����κ��� ����� ���������� ä��������
	// ======================
	// Time Complexity : O(n)
	int trap1(vector<int>& height) {
		int ans = 0;
		int leftMax = 0, rightMax = 0;
		int leftPtr = 0;
		int rightPtr = height.size() - 1;
		
		while (leftPtr < rightPtr)
		{
			if (height[leftPtr] < height[rightPtr])
			{
				if (height[leftPtr] < leftMax)
				{
					ans += leftMax - height[leftPtr];
				}
				else
				{
					leftMax = height[leftPtr];
				}

				leftPtr++;
			}
			else
			{
				if (height[rightPtr] < rightMax)
				{
					ans += rightMax - height[rightPtr];
				}
				else
				{
					rightMax = height[rightPtr];
				}

				rightPtr--;
			}
		}
		
		return ans;
	}
};
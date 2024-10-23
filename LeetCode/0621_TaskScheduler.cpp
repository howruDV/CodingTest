// Leetcode 0621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

#include <vector>
#include <queue>
#include <minmax.h>
using namespace std;

class Solution {
public:
	// ==========================
	// (0) greedy
	// ==========================
	// Time Complexity O(nlogn)

	int leastInterval(vector<char>& tasks, int n) {
		priority_queue<int> taskCount;
		int perTaskCount['Z' - 'A' + 1];

		// 1. count task
		for (int i = 0; i < tasks.size(); ++i)
		{
			perTaskCount[tasks[i] - 'A']++;
		}

		for (int i = 0; i < ('Z' - 'A' + 1); ++i)
		{
			if (perTaskCount[i] > 0)
			{
				taskCount.push(perTaskCount[i]);
			}
		}

		// 2. create schedule
		int ans = 0;
		int schedule_1path = 0;

		while (!taskCount.empty())
		{
			// 이전 schedule 개수 체크
			if (schedule_1path > 0 && schedule_1path < n + 1)
			{
				ans += (n + 1) - schedule_1path;
			}

			// 새로운 schedule 계산
			schedule_1path = 0;
			vector<int> taskRemain;

			while (schedule_1path <= n && !taskCount.empty())
			{
				int priorityTask = taskCount.top() - 1;
				taskCount.pop();

				if (priorityTask > 0)
				{
					taskRemain.push_back(priorityTask);
				}

				schedule_1path++;
			}

			ans += schedule_1path;

			for (int i = 0; i < taskRemain.size(); ++i)
			{
				taskCount.push(taskRemain[i]);
			}
		}

		return ans;
	}

	// ==========================
	// (1) formula
	// ==========================
	// Time Complexity O(n)

	int leastInterval_formula(vector<char>& tasks, int n) {
		int maxCount = 0;
		int perTaskCount['Z' - 'A' + 1];

		// 1. count task
		for (int i = 0; i < tasks.size(); ++i)
		{
			maxCount = max(maxCount, ++perTaskCount[tasks[i] - 'A']);
		}

		int maxTaskCount = 0;

		// 2. calc schedule
		for (int i = 0; i < ('Z' - 'A' + 1); ++i)
		{
			if (perTaskCount[i] == maxCount)
			{
				maxTaskCount++;
			}
		}

		return max(int(tasks.size()), ((maxCount - 1) * (n + 1) + maxTaskCount));
	}
};
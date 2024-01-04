// LeetCode 0621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// ----------------------------------
// idea: insert people by height order
// record current remaining front idx
// ----------------------------------
// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution {
private:
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b)
    {
        return b.second > a.second;
    }

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskList;
        priority_queue<int, char, greater<>> taskRec;
        int len = 0;

        for (char it : tasks)
        {
            taskList[it]++;
        }
        sort(taskList.begin(), taskList.end(), cmp);

        int taskIdx = 0;
        int curSize = 1;
        while (!taskList.empty())
        {
            // n 되기 이전: (즉, 최초 n만큼) taskList삽입
            if (len < n)
            {
                char curTask = taskList[taskIdx];

                if (taskList.size() >= len)
                    taskRec.pop();
                taskRec.emplace((len, curTask));

                
                if (--taskList[taskIdx] == 0)
                    taskList.erase(curTask);

                if (++taskIdx >= taskList.size())
                    taskIdx = 0;
                
                len++;
            }

            // n부터는
            else
            {
                char curTask = taskRec.top().second;
                int prevIdx = taskRec.top().first;
                
                if (curSize <= n + 1)
                {

                    if (taskList.size() >= len)
                        taskRec.pop();
                    taskRec.emplace((len, curTask));


                    if (--taskList[taskIdx] == 0)
                        taskList.erase(curTask);

                    if (++taskIdx >= taskList.size())
                        taskIdx = 0;

                    len++;
                }
            }
        }
    }
};
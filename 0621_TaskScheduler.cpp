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
        return a.second > b.second;
    }

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskList;
        int len = 0;

        for (char it : tasks)
        {
            taskList[it]++;
        }
        //sort(taskList.begin(), taskList.end(), cmp);

        int taskIdx = 0;
        int remainN = n;

        vector<int> eraseIdx;
        while (!taskList.empty())
        {
            if (taskIdx < taskList.size())
            {
                taskList[taskIdx] -= 1;
                if (taskList[taskIdx] == 0)
                    eraseIdx.push_back(taskIdx);
                
                taskIdx++;
            }

            if (--remainN <= 0)
            {
                remainN = n;
                taskIdx = 0;
                for (int i=0; i<=eraseIdx.size(); ++i)
                    taskList.erase(i);
            }

            len++;
        }

        return len;
    }
};
// Leetcode 0406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    // =============================
    // (0) 키가 작은 순으로 위치 고정
    // =============================
    // Time Complexity O(nlogn)
    void pushQueue(const vector<int>& people, vector<vector<int>>& outQueue)
    {
        int height = people[0];
        int spaceCount = people[1];

        for (int i = 0; i < outQueue.size(); ++i)
        {
            if (!outQueue[i].empty())
            {
                if (outQueue[i][0] == height)
                {
                    spaceCount--;
                }

                continue;
            }

            if (spaceCount > 0)
            {
                spaceCount--;
                continue;
            }

            outQueue[i] = people;
            break;
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size());
        sort(people.begin(), people.end());
        
        for (int i = 0; i < people.size(); ++i)
        {
            pushQueue(people[i], ans);
        }

        return ans;
    }

    // =============================
    // (1) 키가 큰 순으로 삽입
    // =============================
    // Time Complexity O(nlogn)
    struct Comp {
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        }
    };

    vector<vector<int>> reconstructQueue_bigOrder(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, Solution::Comp> maxHeap (people.begin(), people.end());
        
        while (!maxHeap.empty())
        {
            int frontSpace = maxHeap.top()[1];
            ans.insert(ans.begin() + frontSpace, maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }
};
// LeetCode 0406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/
#include <vector>
#include <algorithm>
using namespace std;

// ----------------------------------
// idea: insert people by height order
// record current remaining front idx
// ----------------------------------
// - Time Complexity O(n^2)
// - Space Complexity O(n)
class Solution0 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret(people.size());
        int curHeight = -1;
        int remainFront = 0;
        sort(people.begin(), people.end());

        // 1. insert people by height order
        for (vector<int> it : people)
        {
            // 2. check current height
            if (curHeight != it[0])
            {
                curHeight = it[0];
                while (!ret[remainFront].empty())
                    remainFront++;
            }

            // case: insert not front
            // - check if other people is in front
            int check = 0;
            if (it[1] != 0)
            {
                for (int i = 1; i <= it[1]; ++i)
                {
                    while (!ret[i + remainFront + check].empty() && ret[i + remainFront + check][0] != curHeight)
                        check++;
                }
            }

            ret[it[1] + remainFront + check] = it;
        }

        return ret;
    }
};

// - Time Complexity O(n^2)
// - Space Complexity O(n)
class Solution1 {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0]) return b[1] > a[1];
        return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret;
        sort(people.begin(), people.end(), cmp);

        // 1. insert dec order
        // - as a result, when same priority, lower height insert in front of higher height 
        for (vector<int> it : people)
            ret.insert(ret.begin() + it[1], it);

        return ret;
    }
};
// Leetcode 0347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
// Time Complexity O(nlogn)

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Time Complexity O(nlogn)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;   // num, count

        // 1. create unorderd map
        for (int num : nums)
        {
            numCount[num]++;
        }

        // 2. sort
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;

        for (pair<int, int> it : numCount)
        {
            pq.push({ it.second, it.first });   // count, num
        }

        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top().second); // num
            pq.pop();
        }

        return ans;
    }
};
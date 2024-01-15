// LeetCode 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
// - time complexity must be better than O(n log n)

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// maxHeap by vector ver
// - Time Complexity O(nlogn)
// - Space Complexity O(n)
class Solution0 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        vector<pair<int, int>> heap;
        vector<int> ret;

        // 0. explore nums
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
        {
            unordered_map<int, int>::iterator mapIter = numCount.find(*iter);

            // case: none exist
            if (mapIter == numCount.end())
                numCount.insert(make_pair(*iter, 1));
            // case: already exist
            else
                mapIter->second++;
        }

        // 1. find desc order
        // 1.0. make heap vector
        for (unordered_map<int, int>::iterator iter = numCount.begin(); iter != numCount.end(); ++iter)
            heap.push_back(make_pair(iter->second, iter->first));
        make_heap(heap.begin(), heap.end());

        // 1.1. maxheap
        for (int i = 0; i < k; ++i)
        {
            pop_heap(heap.begin(), heap.end());
            ret.push_back(heap.back().second);
            heap.pop_back();
        }

        return ret;
    }
};

// maxHeap by priority_queue ver
// priority_queue: STL container that use HEAP structure
// - Time Complexity O(nlogn)
// - Space Complexity O(n)
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        priority_queue<pair<int, int>> heap;
        vector<int> ret;

        // 0. count nums
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
            numCount[*iter]++;

        // 1. find desc order
        for (unordered_map<int, int>::iterator iter = numCount.begin(); iter != numCount.end(); ++iter)
            heap.push(make_pair(iter->second, iter->first));

        for (int i = 0; i < k; ++i)
        {
            ret.push_back(heap.top().second);
            heap.pop();
        }

        return ret;
    }
};
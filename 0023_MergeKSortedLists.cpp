// LeetCode 023. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// recursion ver
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2)
    {
        if (!L1)
            return L2;
        if (!L2)
            return L1;

        if (L1->val < L2->val)
        {
            L1->next = mergeTwoLists(L1->next, L2);
            return L1;
        }
        else
        {
            L2->next = mergeTwoLists(L1, L2->next);
            return L2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        ListNode* ret = lists[0];
        for (int i = 1; i < lists.size(); ++i)
            ret = mergeTwoLists(ret, lists[i]);

        return ret;
    }
};

// LeetCode 021. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// try 0: iteratively
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* ret = list1;
        ListNode* pMerged = nullptr;

        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        // 0. merge two lists
        while (list1 && list2)
        {
            if (list1->val == list2->val)
            {
                ListNode* tmp = list1->next;
                if (pMerged)
                    pMerged->next = list1;
                list1->next = list2;

                pMerged = list2;
                list1 = tmp;
                list2 = list2->next;
            }
            else if (list1->val > list2->val)
            {
                if (pMerged)
                    pMerged->next = list2;
                else
                    ret = list2;
                pMerged = list2;

                list2 = list2->next;
            }
            else
            {
                if (pMerged)
                    pMerged->next = list1;
                pMerged = list1;

                list1 = list1->next;
            }
        }

        // 1. attach remaining nodes
        ListNode* remaining = list1 ? list1 : list2;
        if (remaining)
            pMerged->next = remaining;

        return ret;
    }
};

// try 1:  recursively
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if (!list1) return list2;
        else if (!list2) return list1;

        if (list1->val > list2->val)
        {
            list2->next = merge(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = merge(list1->next, list2);
            return list1;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        return merge(list1, list2);
    }
};
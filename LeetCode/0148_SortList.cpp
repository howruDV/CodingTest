// Leetcode 0148. Sort List
// https://leetcode.com/problems/sort-list/
// Time Complexity O(nlogn)
// Space Complexity O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity O(nlogn)
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode ans(0);
        ListNode* last = &ans;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                last->next = list1;
                list1 = list1->next;
            }
            else
            {
                last->next = list2;
                list2 = list2->next;
            }

            last = last->next;
        }

        last->next = list1 ? list1 : list2;
        return ans.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        // 1. ÂÉ°·
        ListNode* prev = nullptr;
        ListNode* mid = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        head = sortList(head);
        mid = sortList(mid);

        // 2. ÇÕÄ§
        return merge(head, mid);
    }
};
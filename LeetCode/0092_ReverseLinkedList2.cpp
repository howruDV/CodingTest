// LeetCode 092. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/
// -The number of nodes in the list is n (1 <= n)

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution {
public:
    ListNode* reverse(ListNode** pphead, int len) {
        ListNode* head = *pphead;
        ListNode* mid = nullptr;
        ListNode* tail = nullptr;
        int i = 0;

        while (i < len)
        {
            tail = mid;
            mid = head;
            head = head->next;

            mid->next = tail;
            ++i;
        }

        *pphead = mid;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        ListNode* pNode = head;
        ListNode* pLNode;
        ListNode* pRNode;
        for (int i = 0; pNode; ++i)
        {
            if (i == left - 2)
                pLNode = pNode;
            // 0. reverse section
            else if (i == left - 1)
            {
                pRNode = reverse(&pNode, right - left + 1);

                // link with left section
                if (left == 1)
                {
                    head = pNode;
                }
                else
                    pLNode->next = pNode;
            }
            // 1. after reverse, link with right section
            else if (i == right - 1)
                pNode->next = pRNode;

            pNode = pNode->next;
        }

        return head;
    }
};
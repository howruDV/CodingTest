// LeetCode 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
// - implement either iteratively and recursively

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// iteratively
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    // iteratively
    ListNode* reverseList(ListNode* head) {
        ListNode* pMid = nullptr;
        ListNode* pTail = nullptr;

        while (head)
        {
            pTail = pMid;
            pMid = head;
            head = head->next;

            pMid->next = pTail;
        }

        return pMid;
    }
};

// recursively
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    ListNode* LinkFromNext(ListNode* head)
    {
        if (!head)
            return nullptr;

        ListNode* reverseHead = LinkFromNext(head->next);
        if (head->next)
            head->next->next = head;

        if (reverseHead)
            return reverseHead;
        return head;
    }

    // recursively
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;

        ListNode* reverseHead = LinkFromNext(head);
        head->next = nullptr;
        return reverseHead;
    }
};
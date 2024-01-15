// LeetCode 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/submissions/
// - space complexity: extra O(1)
// - time complexity: O(n)

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* pNode = head;
        ListNode* evenListHead = new ListNode;
        ListNode* evenList = evenListHead;

        // 0. link per group
        while (pNode)
        {
            ListNode* even = pNode->next;
            // case: endNode
            if (!even)
            {
                evenList->next = nullptr;
                evenList = pNode;
                break;
            }
            // case: progress
            else
            {
                pNode->next = even->next;
                evenList->next = even;
                if (pNode->next)
                    evenList = evenList->next;
                else
                    evenList = pNode;   // save end of odd list
                pNode = pNode->next;
            }
        }

        // 1. link two group
        evenList->next = evenListHead->next;
        delete evenListHead;
        return head;
    }
};
// LeetCode 02. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode;
        ListNode* retHead = ret;
        int val = 0;

        while (l1 || l2 || val != 0)
        {
            // 0. add new node
            ret->next = new ListNode;
            ret = ret->next;

            // 1. process current digit
            if (l1)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                val += l2->val;
                l2 = l2->next;
            }

            // 2. save & round-up
            if (val < 10)
            {
                ret->val = val;
                val = 0;
            }
            else
            {
                val %= 10;
                ret->val = val;
                val = 1;
            }
        }

        ret = retHead->next;
        delete retHead;
        return ret;
    }
};
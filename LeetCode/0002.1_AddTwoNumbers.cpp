// LeetCode 0002. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Time Complexity O(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool bOver = false;
        ListNode* ans = l1;
        ListNode* cur = ans;

        // 0. add two num
        while (l1 || l2)
        {
            int sum = l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;
            sum += bOver ? 1 : 0;
            bOver = false;

            if (sum >= 10)
            {
                sum -= 10;
                bOver = true;
            }

            cur->val = sum;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            if (l1 || l2)
            {
                cur->next = l1 ? l1 : l2;
                cur = cur->next;
            }
        }

        // 1. calc last over value
        if (bOver)
        {
            cur->next = new ListNode(1);
        }

        return ans;
    }
};
// LeetCode 024. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// try1: iteratively
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* node0 = head;
        ListNode* node1 = nullptr;

        // 0. point return head
        if (head && node0->next)
            head = node0->next;

        // 1. swap two node
        while (node0)
        {
            ListNode* lastNode = node1;
            node1 = node0->next;

            // case: progress
            if (node1)
            {
                if (lastNode)
                    lastNode->next = node1;
                node0->next = node1->next;
                node1->next = node0;

                node1 = node0; // save lastNode;
                node0 = node0->next;
            }
            // case: endNode
            else
                break;
        }

        return head;
    }
};

// try2: recursively
// - reverse each sections
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* pairNode = head->next;
        ListNode* next = pairNode->next;
        pairNode->next = head;

        head->next = swapPairs(next);
        return pairNode;
    }
};

#include <queue>
using namespace std;
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// =====================
// (0) Merge each List
// =====================
// Time Complexity O(kn)
class Solution0 {
public:
    // Time Complexity : O(n)
    ListNode* mergeTwoList(ListNode* list0, ListNode* list1)
    {
        if (!list0)
            return list1;
        else if (!list1)
            return list0;

        ListNode* ans = new ListNode();
        ListNode* node1 = list0;
        ListNode* node2 = list1;
        list0 = ans;

        while (node1 && node2)
        {
            if (node1->val <= node2->val)
            {
                list0->next = node1;
                node1 = node1->next;
            }
            else
            {
                list0->next = node2;
                node2 = node2->next;
            }

            list0 = list0->next;
        }

        if (node1 || node2)
        {
            list0->next = node1 ? node1 : node2;
        }

        list0 = ans->next;
        delete ans;
        return list0;
    }

    // Time Complexity : O(kn)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;

        for (int i = 0; i < lists.size(); ++i)
        {
            ans = mergeTwoList(ans, lists[i]);
        }

        return ans;
    }
};

// =====================
// (1) Priority Queue
// =====================
// Time Complexity O(nlogn)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        
        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode* next = lists[i];

            while (next)
            {
                pq.push({ next->val, next });
                next = next->next;
            }
        }

        ListNode* ans = new ListNode;
        ListNode* curNode = ans;

        while (!pq.empty())
        {
            ListNode* nextNode = pq.top().second;
            pq.pop();

            curNode->next = nextNode;
            nextNode->next = nullptr;
            curNode = nextNode;
        }

        curNode = ans->next;
        delete ans;
        return curNode;
    }
};
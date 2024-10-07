// LeetCode 0024. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// ==========
	// (0) iter
	// ==========
	// Time Complexity O(n)
	ListNode* swapPairs(ListNode* head) {
		if (!head)
			return nullptr;

		ListNode* ans = new ListNode;
		ListNode* last = ans;

		// 0. swap pair
		while (head && head->next)
		{
			ListNode* Node0 = head;
			ListNode* Node1 = head->next;
			head = head->next->next;

			last->next = Node1;
			Node1->next = Node0;
			Node0->next = head;
			last = Node0;
		}

		last->next = head;

		// 1. return
		head = ans->next;
		delete ans;
		return head;
	}

	// =============
	// (1) recursion
	// =============
	// Time Complexity O(n)
	ListNode* swapPairs_recur(ListNode* head) {
		if (!head || !head->next)
			return head;

		ListNode* Pair = head->next;
		ListNode* NextPair = head->next->next;

		Pair->next = head;
		head->next = swapPairs_recur(NextPair);
		return Pair;
	}
};
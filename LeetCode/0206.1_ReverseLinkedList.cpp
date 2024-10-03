// LeetCode 0206. Reverse Linked List
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

class Solution {
	// ===============
	// (0) iteratively
	// ===============
	// Time Complexity : O(n)
	ListNode* reverseList_iter(ListNode* head) {
		ListNode* mid = nullptr;
		ListNode* tail = nullptr;

		while (head)
		{
			tail = mid;
			mid = head;
			head = head->next;

			mid->next = tail;
		}

		return mid;
	}

	// ===============
	// (1) recursively
	// ===============
	// Time Complexity : O(n)
	ListNode* Recursively(ListNode* tail, ListNode* mid, ListNode* head)
	{
		if (!head)
			return mid;

		head = Recursively(mid, head, head->next);
		mid->next = tail;
		return head;
	}

	ListNode* reverseList_recur(ListNode* head) {
		Recursively(nullptr, nullptr, head);
		return head;
	}
};
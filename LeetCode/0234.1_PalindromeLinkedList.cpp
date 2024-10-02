// LeetCode 0234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
// Time Complexity : O(n)
// Space Complexity : O(1)

struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Time Complexity : O(n)
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = slow;
		ListNode* prev = nullptr;

		// 1. find half point
		while (fast && fast->next)
		{
			head = head->next;
			fast = fast->next->next;

			slow->next = prev;
			prev = slow;
			slow = head;
		}

		if (fast)
		{
			head = head->next;
		}

		// 2. check palindrome
		while (prev && head)
		{
			if (prev->val != head->val)
				return false;

			prev = prev->next;
			head = head->next;
		}

		return true;
	}
};
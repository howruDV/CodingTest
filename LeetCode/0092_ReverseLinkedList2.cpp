// LeetCode 0092. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/
// one pass

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
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		int count = 0;
		ListNode* ans = new ListNode(0, head);
		ListNode* reversePrev = nullptr;
		ListNode* reverseStart = nullptr;
		ListNode* prev = nullptr;
		ListNode* mid = nullptr;

		head = ans;
		while (head)
		{
			prev = mid;
			mid = head;
			head = head->next;

			if (count == left)
			{
				reversePrev = prev;
				reverseStart = mid;
			}
			else if (count > left && count < right)
			{
				mid->next = prev;
			}
			else if (count == right)
			{
				reversePrev->next = mid;
				mid->next = prev;
				reverseStart->next = head;
			}

			count++;
		}

		head = ans->next;
		delete ans;
		return head;
	}
};
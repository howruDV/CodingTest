// LeetCode 0328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/
// Space Complexity: O(1)
// Time Complexity: O(n)

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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next)
			return head;

		ListNode* OddHead = new ListNode();
		ListNode* OddLast = OddHead;
		ListNode* EvenHead = new ListNode();
		ListNode* EvenLast = EvenHead;
		bool IsOdd = true;

		// 0. group odd & even
		while (head)
		{
			ListNode* Next = head->next;
			head->next = nullptr;

			if (IsOdd)
			{
				OddLast->next = head;
				OddLast = head;
			}
			else
			{
				EvenLast->next = head;
				EvenLast = head;
			}

			IsOdd = !IsOdd;
			head = Next;
		}

		// 1. merge
		head = OddHead->next;
		OddLast->next = EvenHead->next;
		delete OddHead;
		delete EvenHead;

		return head;
	}
};
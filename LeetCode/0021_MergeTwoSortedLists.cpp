// LeetCode 0021. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

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

public:
	// ==========
	// (1) Try1
	// ==========
	// Time Complexity : O(n+m)
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1) return list2;
		if (!list2) return list1;

		ListNode* ans = new ListNode();

		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				ans->next = list1;
				list1 = list1->next;
			}
			else
			{
				ans->next = list2;
				list2 = list2->next;
			}

			ans = ans->next;
		}

		if (list1)
		{
			ans->next = list1;
		}
		else if (list2)
		{
			ans->next = list2;
		}

		// return
		ListNode* tmp = ans->next;
		delete ans;
		return tmp;
	}

	// ==========
	// (2) Àç±Í
	// ==========
	// Time Complexity : O(n+m)
	ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
		if (!list1) return list2;
		if (!list2) return list1;

		if (list1->val < list2->val)
		{
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
};
// LeetCode 0148. Sort List
// https://leetcode.com/problems/sort-list/
// O(n logn) time
// O(1) memory

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

// Merge Sort
// Time Complexity O(nlog(n))
// Space Complexity O(n)
class Solution {
private:
	ListNode* MergeSort(ListNode* start)
	{
		if (!start) return nullptr;
		else if (!start->next) return start;

		// 0. find mid node
		ListNode* mid = start;
		ListNode* tmp = start->next;
		while (tmp && tmp->next)
		{
			mid = mid->next;
			tmp = tmp->next->next;
		}

		// 1. divide
		tmp = mid->next;
		mid->next = nullptr;
		ListNode* sortL = MergeSort(start);
		ListNode* sortR = MergeSort(tmp);

		// 2. conqure
		// head node
		ListNode* retHead;
		ListNode* ret = new ListNode(-1);
		retHead = ret;

		// ascend order
		while (sortL && sortR)
		{
			if (sortL->val < sortR->val)
			{
				ret->next = sortL;
				sortL = sortL->next;
			}
			else
			{
				ret->next = sortR;
				sortR = sortR->next;
			}
			ret = ret->next;
		}
		if (sortL)
			ret->next = sortL;
		else if (sortR)
			ret->next = sortR;

		ret = retHead->next;
		delete(retHead);
		return ret;
	}

public:
	ListNode* sortList(ListNode* head) {
		if (!head) return nullptr;
		return MergeSort(head);
	}
};
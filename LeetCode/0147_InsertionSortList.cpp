// LeetCode 0147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// Insertion Sort
// Time Complexity O(n^2)
// Space Complexity O(1)
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head->next) return head;
		ListNode* retCur = new ListNode(INT_MIN);
		ListNode* retHead = retCur;

		while (head)
		{
			// ascend explore
			while (retCur->next && retCur->next->val <= head->val)
				retCur = retCur->next;
			ListNode* next = head->next;
			head->next = retCur->next;
			retCur->next = head;

			retCur = retHead;
			head = next;
		}

		retCur = retHead->next;
		delete(retHead);
		return retCur;
	}
};
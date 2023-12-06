// LeetCode 239. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
// - O(n) time and O(1) space

struct ListNode 
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// try 0
// - 전체 length를 구하는 방식
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution0 {
public:
    bool isPalindrome(ListNode* head) {
        size_t len = 0;
        ListNode* pHead = head;
        ListNode* pNode = head; // mid
        ListNode* pTail = nullptr;

        // 0. Get Length of List
        while (pNode)
        {
            pNode = pNode->next;
            len++;
        }

        // 1. Pass Forward & ReLink
        pNode = nullptr;
        for (size_t i = 0; i < len / 2; ++i)
        {
            pTail = pNode;
            pNode = pHead;
            pHead = pHead->next;

            pNode->next = pTail;
        }
        if (len % 2 == 1)
            pHead = pHead->next;

        // 2. Compare Forward & Backard
        while (pNode != nullptr)
        {
            if (pNode->val != pHead->val)
                return false;
            pNode = pNode->next; //reverse
            pHead = pHead->next; //forward
        }
        return true;
    }
};

// try 1
// - length를 세는 대신, 2배 빨리 진행해 끝을 체크하는 Fast ptr 생성
// - Time Complexity O(n)
// - Space Complexity O(1)
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* pFast = head;
        ListNode* pSlow = head;
        ListNode* pTail = nullptr;

        // 0. Pass Backword & ReLink
        while (pFast && pFast->next)
        {
            head = head->next;
            pFast = pFast->next->next; //odd

            pSlow->next = pTail; //ReLink
            pTail = pSlow;
            pSlow = head;
        }
        if (pFast)
            head = head->next;

        // 1. Compare Forward & Backard
        while (head)
        {
            if (pTail->val != head->val)
                return false;
            pTail = pTail->next; //reverse
            head = head->next; //forward
        }
        return true;
    }
};
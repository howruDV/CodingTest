// LeetCode 938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/// [TIP: make IO fast]
/// ```
/// ios_base::sync_with_stdio(false);
/// cin.tie(nullptr);
/// cout.tie(nullptr);
/// ```
/// Cpp compiler: C�� Cpp�� ��� ������� ����ȭ�� (ȥ�� ��� ����)
/// - sync_with_stdio(false): ����ȭ�� ���� ������ Cpp ����� ���� ���
/// - cin/cout.tie(nullptr): cin, cout�� stream�� ���� ǰ
/// - WARING: thread ���� ����, C�� Cpp ����� ȥ�� X

// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
private:
	int SubSum(TreeNode* node, int low, int high) {
		if (!node) return 0;

		int sum = 0;
		
		// 1. if value in range
		if (node->val >= low && node->val <= high)
			sum = node->val;

		// 2. traversal child
		sum += SubSum(node->left, low, high);
		sum += SubSum(node->right, low, high);

		return sum;
	}

public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int ret = SubSum(root, low, high);
		return ret;
	}
};
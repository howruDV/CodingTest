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
/// Cpp compiler: C와 Cpp의 모든 입출력을 동기화함 (혼용 허용 위함)
/// - sync_with_stdio(false): 동기화를 꺼서 독립된 Cpp 입출력 버퍼 사용
/// - cin/cout.tie(nullptr): cin, cout의 stream을 따로 품
/// - WARING: thread 사용시 주의, C와 Cpp 입출력 혼용 X

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
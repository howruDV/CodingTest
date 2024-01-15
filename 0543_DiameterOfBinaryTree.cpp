// LeetCode 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
using namespace std;
#include <minmax.h>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
private:
	int BtwRootOneChild = 0;

private:
	int BtwRootTwoChild(TreeNode* node)
	{
		// leaf node: mark -1
		if (!node) return -1;

		// 0. get SubTree Diameter
		int left = BtwRootTwoChild(node->left);
		int right = BtwRootTwoChild(node->right);

		// 1. calculate two case: (1)pass parent or (2)not
		int LR = left + right + 2;
		int LL = max(left, right) + 1;
		BtwRootOneChild = max(BtwRootOneChild, LR);

		return LL;
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		int ret = BtwRootTwoChild(root);
		ret = max(BtwRootOneChild, ret);

		return ret;
	}
};
// LeetCode 226. Invert Binary Tree
// https://leetcode.com/problems/longest-univalue-path/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Time Complexity O(N)
// Space Complexity O(N)
class Solution {
private:
	TreeNode* ExchangeChilds(TreeNode* node)
	{
		// leaf node: return
		if (!node->left && !node->right) return node;

		// 1. exchange each subtree
		if (node->left)
			ExchangeChilds(node->left);
		if (node->right)
			ExchangeChilds(node->right);

		// 2. exchange child position
		TreeNode* tmp = node->left;
		node->left = node->right;
		node->right = tmp;

		return node;
	}

public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return nullptr;

		return ExchangeChilds(root);
	}
};
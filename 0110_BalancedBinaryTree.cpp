// LeetCode 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
#include <minmax.h>
#include <stdlib.h>
using namespace std;

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
	int GetHeight(TreeNode* node)
	{
		// leaf node: height 1
		if (!node) return 0;
		else if (!node->left && !node->right) return 1;

		// 1. get childs height
		int left = GetHeight(node->left);
		int right = GetHeight(node->right);

		// 2. check unblanced (mark -1)
		if (left < 0 || right < 0 || abs(left - right) > 1)
			return -1;

		return(max(left, right) + 1);
	}

public:
	bool isBalanced(TreeNode* root) {
		if (!root) return true;

		int rootHeight = GetHeight(root);
		if (rootHeight < 0)
			return false;
		return true;
	}
};
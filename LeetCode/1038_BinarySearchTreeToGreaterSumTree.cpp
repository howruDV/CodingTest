// LeetCode 1038. Binary Search Tree to Greater Sum Tree
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
	int CreateGrtNode(TreeNode* cur, TreeNode* largestAnc) {
		if (!cur) return 0;

		int iCurSum = cur->val;

		// case: can't progress right child
		if (!cur->right && largestAnc->val > cur->val)
		{
			cur->val += largestAnc->val;
			iCurSum = cur->val;
		}

		if (cur->right)
		{
			// 1. create right child
			int right = CreateGrtNode(cur->right, largestAnc->val>cur->val?largestAnc:cur);
		
			// 2. update current node value (+right child value)
			cur->val += right;
			iCurSum = cur->val;
		}

		if (cur->left)
		{
			// 3. create left child (+current value)
			int left = CreateGrtNode(cur->left, largestAnc->val > cur->val ? largestAnc : cur);
			iCurSum = left;
		}

		return iCurSum;
	}

public:
	TreeNode* bstToGst(TreeNode* root) {
		CreateGrtNode(root, root);
		return root;
	}
};

// LeetCode 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

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
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2) return nullptr;
		else if (!root1) return root2;
		else if (!root2) return root1;

		TreeNode* newNode = new TreeNode;
		newNode->val = root1->val + root2->val;

		newNode->left = mergeTrees(root1->left, root2->left);
		newNode->right = mergeTrees(root1->right, root2->right);

		return newNode;
	}
};
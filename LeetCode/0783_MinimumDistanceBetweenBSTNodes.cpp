// LeetCode 783. Minimum Distance Between BST Nodes
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// 문제 부연설명: value의 최소 차이값 구하기
#include <vector>
#include <minmax.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// idea : min diff between (1) current parent-childs (2) prev - current
// Time Complexity O(n)
// Space Complexity O(n)
class Solution0 {
private:
	TreeNode* prev = nullptr;

private:
	int Traversal(TreeNode* node)
	{
		int minDiff;

		// 1. diff within current node - child (Degree 0, 1, 2)
		if (!node->left && !node->right)
			minDiff = 100000;
		else if (!node->left || !node->right)
			minDiff = node->left ? node->val - node->left->val : node->right->val - node->val;
		else
			minDiff = min(node->val - node->left->val, node->right->val - node->val);
		if (minDiff == 1) return minDiff;

		// 2. explore down (inorder traversal), diff within prev - current
		// 2.1 Left Child
		if (node->left)
			minDiff = min(minDiff, Traversal(node->left));

		// 2.2 Current Update
		minDiff = prev ? min(minDiff, node->val - prev->val) : minDiff;
		prev = node;

		// 2.3 Right Child
		if (node->right)
			minDiff = min(minDiff, Traversal(node->right));

		return minDiff;
	}

public:
	int minDiffInBST(TreeNode* root) {
		int ret = Traversal(root);
		return ret;
	}
};

// Time Complexity O(n)
// Space Complexity O(n)
class Solution1 {
private:
	vector<int> vecInorder;

	void InorderTraversal(TreeNode* node)
	{
		if (!node) return;
		InorderTraversal(node->left);
		vecInorder.push_back(node->val);
		InorderTraversal(node->right);
	}

public:
	int minDiffInBST(TreeNode* root) {
		int ret = INT_MAX;
		InorderTraversal(root);
		for (int i = 1; i < vecInorder.size(); ++i)
			ret = min(ret, vecInorder[i] - vecInorder[i - 1]);

		return ret;
	}
};
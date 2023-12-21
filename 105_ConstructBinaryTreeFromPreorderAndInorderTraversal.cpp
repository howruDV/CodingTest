// LeetCode 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// idea: preorder의 첫번째 값 = root node
// - root는 inorder의 범위를 쪼갤 수 있음
// Time Complexity O(n^2)
// Space Complexity O(n^2)
class Solution {
private:
	TreeNode* SplitedTree(vector<int>& preorder, vector<int> inorder, int& preIdx)
	{
		// trivial case:
		if (inorder.empty())
			return nullptr;

		// 1. find root idx & preorder progress
		int splitIdx = find(inorder.begin(), inorder.end(), preorder[preIdx++]) - inorder.begin();
		TreeNode* node = new TreeNode(inorder[splitIdx]);

		// 2. compose childs
		node->left = SplitedTree(preorder, vector<int>(inorder.begin(), inorder.begin()+splitIdx), preIdx);
		node->right = SplitedTree(preorder, vector<int>(inorder.begin()+splitIdx+1, inorder.end()), preIdx);

		return node;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		int preIdx = 0;
		return SplitedTree(preorder, inorder, preIdx);
	}
};
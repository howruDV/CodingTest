// LeetCode 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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

// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
private:
	TreeNode* createChild(vector<int>& nums, int begin, int end)
	{
		// trivial case
		if (end<begin) return nullptr;

		// 1. find current mid (root)
		TreeNode* parent = new TreeNode;
		int rootIdx = begin + (end - begin + 1) / 2;
		parent->val = nums[rootIdx];

		// 2. create childs
		TreeNode* leftChild = createChild(nums, begin, rootIdx-1);
		TreeNode* rightChild = createChild(nums, rootIdx + 1, end);
		parent->left = leftChild;
		parent->right = rightChild;

		return parent;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = createChild(nums, 0, nums.size() - 1);
		return root;
	}
};
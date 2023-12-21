// LeetCode 687. Longest Univalue Path
// https://leetcode.com/problems/longest-univalue-path/
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

// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
private:
	int LongestSubPath;

private:
	int LongestPath(TreeNode* node)
	{
		// leaf node: return
		if (!node) return 0;
		else if (!node->left && !node->right) return 0;

		// 0. Get SubTree Univalue Length
		int LL = LongestPath(node->left);
		int RR = LongestPath(node->right);

		// 1. Update Length : dosent pass parent
		if (node->left)
		{
			// case: Parent - Child have same value
			if (node->val == node->left->val)
				LL++;
			// case: Parent - Child have different value, Reset Length
			else if (LL != 0)
			{
				LongestSubPath = max(LongestSubPath, LL);
				LL = 0;
			}
		}

		if (node->right)
		{
			if (node->val == node->right->val)
				RR++;
			else if (RR != 0)
			{
				LongestSubPath = max(LongestSubPath, RR);
				RR = 0;
			}
		}

		// 2. Update Length : pass parent
		if (node->left && node->right
			&& node->val == node->left->val && node->val == node->right->val)
			LongestSubPath = max(LongestSubPath, LL + RR);

		return max(LL, RR);
	}

public:
	int longestUnivaluePath(TreeNode* root) {
		int ret = LongestPath(root);
		ret = max(ret, LongestSubPath);

		return ret;
	}
};
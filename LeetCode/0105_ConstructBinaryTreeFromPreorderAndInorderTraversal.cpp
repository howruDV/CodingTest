// Leetcode 0105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	unordered_map<int, int> InorderIdx;

	TreeNode* exportRoot(vector<int>& preorder, vector<int>& inorder, int PreStart, int PreEnd) {
		if (PreStart > PreEnd)
			return nullptr;
		else if (PreStart == PreEnd)
			return new TreeNode(preorder[PreStart]);

		TreeNode* root = new TreeNode(preorder[PreStart]);

		// Preoreder 에서 Right Child의 시작 Idx 찾음
		int RightPreIdx = PreStart + 1;
		for (; RightPreIdx < preorder.size(); ++RightPreIdx)
		{
			if (InorderIdx[preorder[RightPreIdx]] > InorderIdx[root->val])
			{
				break;
			}
		}

		// 재귀
		root->left = exportRoot(preorder, inorder, PreStart + 1, RightPreIdx - 1);
		root->right = exportRoot(preorder, inorder, RightPreIdx, PreEnd);

		return root;
	}
	
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// Inorder Idx 기록
		for (int i = 0; i < inorder.size(); ++i)
		{
			InorderIdx[inorder[i]] = i;
		}

		return exportRoot(preorder, inorder, 0, preorder.size()-1);
	}
};
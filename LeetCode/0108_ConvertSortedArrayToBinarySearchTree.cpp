// Leetcode 0108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pickRoot(vector<int>& nums, int left, int right)
    {
        if (right < left)
            return nullptr;
        if (left == right)
            return new TreeNode(nums[left]);

        int RootIdx = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[RootIdx]);
        root->left = pickRoot(nums, left, RootIdx - 1);
        root->right = pickRoot(nums, RootIdx + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return pickRoot(nums, 0, nums.size() - 1);
    }
};
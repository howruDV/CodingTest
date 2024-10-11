// Leetcode 0543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

#include <minmax.h>
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

// 가장 긴 거리 : 각 자식의 가장 긴 연결 가능한 path 합
class Solution {
public:
    int ans;

    // return max path of subtree
    int dfs(TreeNode* node)
    {
        if (!node)
            return 0;
        
        int left = 0;
        int right = 0;

        if (node->left)
        {
            left = dfs(node->left);
            left++;
        }
        if (node->right)
        {
            right = dfs(node->right);
            right++;
        }

        ans = max(ans, left + right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
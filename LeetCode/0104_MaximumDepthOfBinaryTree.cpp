// Leetcode 0104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <minmax.h>
#include <queue>
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
    // ===========
    // (0) dfs
    // ===========
    int ans;

    void dfs(TreeNode* node, int depth)
    {
        if (!node)
            return;

        depth++;
        ans = max(ans, depth);

        dfs(node->left, depth);
        dfs(node->right, depth);
    }

    int maxDepth(TreeNode* root) {
        ans = 0;
        dfs(root, 0);

        return ans;
    }

    // ===========
    // (1) bfs
    // ===========
    int maxDepth_bfs(TreeNode* root) {
        if (!root)
            return 0;

        int ans = 0;
        queue<TreeNode*> Queue;
        Queue.push(root);

        while (!Queue.empty())
        {
            int size = Queue.size();
            ans++;

            for (int i = 0; i < size; ++i)
            {
                TreeNode* Node = Queue.front();
                Queue.pop();

                if (!Node->left)
                {
                    Queue.push(Node->left);
                }
                if (!Node->right)
                {
                    Queue.push(Node->right);
                }
            }
        }

        return ans;
    }

    // ===========
    // (2) dfs2
    // ===========
    int maxDepth_dfs2(TreeNode* root) {
        if (!root)
            return 0;

        int left = 1;
        int right = 1;

        if (root->left)
        {
            left += maxDepth(root->left);
        }
        if (root->right)
        {
            right += maxDepth(root->right);
        }

        return max(left, right);
    }
};
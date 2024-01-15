// LeetCode 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

// Recursive Traversal (DFS)
// - Time Complexity O(n)
// - Space Complexity O(n)
class Solution0 {
private:
    int DepthTraversal(TreeNode* node, int depth)
    {
        if (!node)  return depth;

        depth++;
        int depthL = DepthTraversal(node->left, depth);
        int depthR = DepthTraversal(node->right, depth);

        return max(depthL, depthR);
    }

public:
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;

        int depth = 0;        
        depth = DepthTraversal(root, depth);

        return depth;
    }
};

// Iterative Traversal (BFS)
// - Time Complexity O(n)
// - Space Complexity O(n)

/// [Condition Error]:
/// for문의 반복 횟수를 지정할 때
/// size를 따로 구하지 않고
/// 바로 queue의 size를 받아 계산하면 오류발생
/// (note: cpp는 for문의 조건 매 순간 새로 확인)

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        deque<TreeNode*> queue;
        int depth = 0;
        queue.push_back(root);

        while (!queue.empty())
        {
            depth++;
            int size = queue.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode* curNode = queue.front();
                if (curNode->left)
                    queue.push_back(curNode->left);
                if (curNode->right)
                    queue.push_back(curNode->right);

                queue.pop_front();
            }
        }

        return depth;
    }
};
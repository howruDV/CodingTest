// LeetCode 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Idea: Level-Traversal
// Time Complexity O(N)
// Space Complexity O(N)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		if (!root) return "";

		string retStr;
		deque<TreeNode*> q;
		q.push_back(root);

		while (!q.empty())
		{
			TreeNode* cur = q.front();
			
			if (cur->left)
				q.push_back(cur->left);
			if (cur->right)
				q.push_back(cur->right);
			
			if (cur)
			{

				retStr += cur->val + ",";
			}
			else
			{
				q.push_back(nullptr);
				q.push_back(nullptr);
				
				retStr += "null,";
			}

			q.pop_front();
		}

		retStr = retStr.substr(0, retStr.size() - 1);
		return retStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		if (data == "") return nullptr;

		deque<TreeNode*> q;
		TreeNode* retTree = nullptr;
		bool bLeft = true;
		int curPos = 1;
		int findPos;

		// root
		if (data[0])
		{
			retTree = new TreeNode;
			retTree->val = int(data[0]);
			q.push_back(retTree);
		}

		// tree (decodes)
		while ((findPos = data.find(',', curPos)) != string::npos)
		{
			TreeNode* newNode;
			
			if (data.substr(curPos, findPos) == "null")
				newNode = nullptr;
			else
			{
				newNode = new TreeNode;
				newNode->val = data[++findPos];
			}

			if (bLeft && q.front())
				q.front()->left = newNode;
			else if (!bLeft)
			{
				q.pop_front();
				if (q.front())
					q.front()->right = newNode;
			}

			q.push_back(newNode);
			bLeft = !bLeft;
			curPos = findPos + 1;
		}

		return retTree;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
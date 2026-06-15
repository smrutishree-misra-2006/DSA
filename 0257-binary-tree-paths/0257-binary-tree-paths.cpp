/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* node, vector<int>& path, vector<string>& ans) {
        if (node == nullptr)
            return;

        path.push_back(node->val);

        // Leaf node
        if (node->left == nullptr && node->right == nullptr) {
            string s = "";
            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1)
                    s += "->";
            }
            ans.push_back(s);
        }

        find(node->left, path, ans);
        find(node->right, path, ans);

        path.pop_back();   // backtrack
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;

        find(root, path, result);

        return result;
    }
};
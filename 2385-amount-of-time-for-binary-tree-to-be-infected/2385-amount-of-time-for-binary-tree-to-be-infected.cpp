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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Create parent mapping and find target node
    TreeNode* markParents(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& parent,
                          int start) {

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* target = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                target = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return target;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* target = markParents(root, parent, start);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int time = 0;

        while (!q.empty()) {

            int sz = q.size();
            bool infected = false;

            for (int i = 0; i < sz; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !vis[node->left]) {
                    infected = true;
                    vis[node->left] = true;
                    q.push(node->left);
                }

                // Right child
                if (node->right && !vis[node->right]) {
                    infected = true;
                    vis[node->right] = true;
                    q.push(node->right);
                }

                // Parent
                if (parent.count(node) && !vis[parent[node]]) {
                    infected = true;
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }

            if (infected)
                time++;
        }

        return time;
    }
};
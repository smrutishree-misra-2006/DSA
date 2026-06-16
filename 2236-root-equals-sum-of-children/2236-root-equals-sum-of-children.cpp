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
 */class Solution {
public:
    bool checkTree(TreeNode* root) {
        // base case: leaf node is always valid
        if (root->left == NULL && root->right == NULL) return true;

        int child = 0;
        if (root->left)  child += root->left->val;
        if (root->right) child += root->right->val;

        return (child == root->val) &&
               checkTree(root->left)  &&   // fix: short-circuits if false
               checkTree(root->right);
    }
};
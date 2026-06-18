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
    TreeNode* helper(vector<int>& postorder, int postStart, int postEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& imap) {

        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        // Root is the last element of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = imap[root->val];

        // Number of nodes in left subtree
        int leftSize = inRoot - inStart;

        // Build left subtree
        root->left = helper(postorder,
                            postStart,
                            postStart + leftSize - 1,
                            inorder,
                            inStart,
                            inRoot - 1,
                            imap);

        // Build right subtree
        root->right = helper(postorder,
                             postStart + leftSize,
                             postEnd - 1,
                             inorder,
                             inRoot + 1,
                             inEnd,
                             imap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> imap;

        for (int i = 0; i < inorder.size(); i++) {
            imap[inorder[i]] = i;
        }

        return helper(postorder,
                      0,
                      postorder.size() - 1,
                      inorder,
                      0,
                      inorder.size() - 1,
                      imap);
    }
};
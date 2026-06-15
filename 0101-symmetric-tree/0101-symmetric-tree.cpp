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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || issymm(root->left,root->right);
    }
    bool issymm(TreeNode* left,TreeNode* right){
        if(left == nullptr || right == nullptr){
            return left == right;
        }
        if(left -> val != right -> val) return false;

        return issymm(left -> left ,right -> right ) && issymm(left -> right ,right -> left);
    }
};
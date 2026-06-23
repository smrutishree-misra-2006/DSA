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

class NodeValue {
public:
    int minNode, maxNode, sum;

    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxSum = 0;

    NodeValue helper(TreeNode* root) {

        // Empty tree is a BST
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if current subtree is BST
        if (left.maxNode < root->val &&
            root->val < right.minNode) {

            int currSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Not a BST
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
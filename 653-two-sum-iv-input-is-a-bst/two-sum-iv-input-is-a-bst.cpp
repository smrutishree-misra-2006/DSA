/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushall(root);
    }

    void pushall(TreeNode* node) {
        while (node) {
            st.push(node);

            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (!reverse)
            pushall(temp->right);
        else
            pushall(temp->left);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // smallest
        BSTIterator r(root, true);  // largest

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;

            if (sum == k)
                return true;
            else if (sum < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};
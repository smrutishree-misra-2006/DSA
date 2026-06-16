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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;  // fix 1: long long, not int
        int ans = 0;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;  // fix 2: normalize here
            long long first, last;

            for (int i = 0; i < size; i++) {
                long long curr = q.front().second - mini;  // fix 3: was `.mmin` (typo), also subtract mini
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curr;
                if (i == size - 1) last = curr;

                if (node->left)
                    q.push({node->left,  curr * 2 + 1});  // fix 4: was `cuu` (typo)
                if (node->right)
                    q.push({node->right, curr * 2 + 2});  // fix 4: was `cuu` (typo)
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};
class Solution {
public:
    int dfs(TreeNode* node, int mx) {
        if (!node) return 0;

        int count = 0;

        if (node->val >= mx) {
            count = 1;
        }

        mx = max(mx, node->val);

        count += dfs(node->left, mx);
        count += dfs(node->right, mx);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
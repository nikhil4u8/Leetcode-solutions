TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p) return NULL;
        TreeNode *cur = root, *ret = NULL, *prev = NULL;
        while (cur) {
            if (cur->left) {
                TreeNode *pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (pre->right != cur) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if (prev == p) ret = cur;
                    prev = cur;
                    cur = cur->right;
                }
            } else {
                if (prev == p) ret = cur;
                prev = cur;
                cur = cur->right;
            }
        }
        return ret;
}
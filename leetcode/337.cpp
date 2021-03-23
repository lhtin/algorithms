class Solution {
public:
    int rob(TreeNode* root) {
      if (!root) {
        return 0;
      }
      int rob_it = root->val +
                   (root->left ? rob(root->left->left) + rob(root->left->right) : 0) +
                   (root->right ? rob(root->right->left) + rob(root->right->right) : 0);
      int not_rob_it = rob(root->left) + rob(root->right);
      return max(rob_it, not_rob_it);
    }
};
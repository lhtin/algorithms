class Solution {
private:
    vector<TreeNode *> res;
public:
    bool isSame(TreeNode *node1, TreeNode *node2) {
      if (!node1 || !node2) {
        return node1 == node2;
      }
      if (node1->val != node2->val) {
        return false;
      }
      return isSame(node1->left, node2->left) && isSame(node1->right, node2->right);
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {

    }
};
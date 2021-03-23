#include "./leetcode.hpp"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (!root) {
        return root;
      }
      TreeNode* left = root->left;
      root->left = invertTree(root->right);
      root->right = invertTree(left);
      return root;
    }

    // 将整棵树的节点翻转
//    TreeNode invertTree(TreeNode root) {
//      // base case
//      if (root == nullptr) {
//        return nullptr;
//      }
//
//      /**** 前序遍历位置 ****/
//      // root 节点需要交换它的左右子节点
//      TreeNode tmp = root.left;
//      root.left = root.right;
//      root.right = tmp;
//
//      // 让左右子节点继续翻转它们的子节点
//      invertTree(root.left);
//      invertTree(root.right);
//
//      return root;
//    }
};


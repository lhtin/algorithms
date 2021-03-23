#include "./leetcode.hpp"

class Solution {
public:
    TreeNode *flatten(TreeNode *left, TreeNode *right) {
      if (!left) {
        return right;
      }
      TreeNode *right2 = flatten(left->right, right);
      left->right = flatten(left->left, right2);
      left->left = nullptr;
      return left;
    }

    void flatten(TreeNode *root) {
      flatten(root, nullptr);
    }
};

// 定义：将以 root 为根的树拉平为链表
//    void flatten(TreeNode root) {
//      // base case
//      if (root == nullptr) return;
//
//      flatten(root.left);
//      flatten(root.right);
//
//      /**** 后序遍历位置 ****/
//      // 1、左右子树已经被拉平成一条链表
//      TreeNode left = root.left;
//      TreeNode right = root.right;
//
//      // 2、将左子树作为右子树
//      root.left = nullptr;
//      root.right = left;
//
//      // 3、将原先的右子树接到当前右子树的末端
//      TreeNode p = root;
//      while (p.right != nullptr) {
//        p = p.right;
//      }
//      p.right = right;
//    }
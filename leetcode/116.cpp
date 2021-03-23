class Node {
public:
    Node* next;
    Node* left;
    Node* right;
};

class Solution {
public:
    Node *connect(Node *root) {
      if (!root) {
        return root;
      }
      Node *cur = root;
      Node *prevChild = nullptr;
      while (cur) {
        if (prevChild) {
          // 连接跨相邻父节点的子节点
          prevChild->next = cur->left;
        }
        if (cur->left) {
          // 连接同父节点的左右子节点
          cur->left->next = cur->right;
        }
        prevChild = cur->right;
        cur = cur->next;
      }
      connect(root->left);
      return root;
    }

    // 主函数
//    Node connect(Node root) {
//      if (root == nullptr) return nullptr;
//      connectTwoNode(root.left, root.right);
//      return root;
//    }
//
//    // 辅助函数
//    void connectTwoNode(Node node1, Node node2) {
//      if (node1 == nullptr || node2 == nullptr) {
//        return;
//      }
//      /**** 前序遍历位置 ****/
//      // 将传入的两个节点连接
//      node1.next = node2;
//
//      // 连接相同父节点的两个子节点
//      connectTwoNode(node1.left, node1.right);
//      connectTwoNode(node2.left, node2.right);
//      // 连接跨越父节点的两个子节点
//      connectTwoNode(node1.right, node2.left);
//    }
};


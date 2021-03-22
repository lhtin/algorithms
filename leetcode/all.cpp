#include "./std.hpp"

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace L226 {
    class Solution {
    public:
        TreeNode *invertTree(TreeNode *root) {
          if (!root) {
            return root;
          }
          TreeNode *left = root->left;
          root->left = invertTree(root->right);
          root->right = invertTree(left);
          return root;
        }
    };
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
}

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    explicit Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

namespace L116 {
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
    };

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
}

namespace L114 {
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
}

namespace L654 {
    class Solution {
    public:
        TreeNode *constructMaximumBinaryTree(vector<int> &nums, int start, int end) {
          if (start > end) {
            return nullptr;
          }
          int maxI = start;
          for (int i = start + 1; i <= end; i += 1) {
            if (nums[i] > nums[maxI]) {
              maxI = i;
            }
          }
          TreeNode *left = constructMaximumBinaryTree(nums, start, maxI - 1);
          TreeNode *right = constructMaximumBinaryTree(nums, maxI + 1, end);
          return new TreeNode(nums[maxI], left, right);
        }

        TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
          return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
        }
    };
}

namespace L652 {
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
}

namespace L297 {
    class Codec {
    private:
        int at;
    public:
        Codec() : at(0) {}

        // Encodes a tree to a single string.
        // 1,2,#,#,3,4,#,#,5,#,#
        string serialize(TreeNode *root) {
          if (!root) {
            return "#";
          }
          string s = to_string(root->val);
          return s + "," + serialize(root->left) + "," + serialize(root->right);
        }

        string getItem(string data) {
          string s = "";
          for (; at < data.size(); at += 1) {
            if (data[at] == ',') {
              at += 1;
              return s;
            } else {
              s += data[at];
            }
          }
          return s;
        }

        // Decodes your encoded data to tree.
        TreeNode *deserialize(string data) {
          string val = getItem(data);
          if (val == "#") {
            return nullptr;
          }
          TreeNode *node = new TreeNode(stoi(val));
          node->left = deserialize(data);
          node->right = deserialize(data);
          return node;
        }
    };
}

namespace L341 {
//    class NestedIterator {
//        int i;
//        vector<int> res;
//    public:
//        NestedIterator(vector <NestedInteger> &nestedList) {
//          i = 0;
//          flatten(nestedList);
//        }
//
//        void flatten(vector <NestedInteger> &list) {
//          if (list.size() == 0) {
//            return;
//          }
//          for (int i = 0; i < list.size(); i += 1) {
//            NestedInteger item = list[i];
//            if (item.isInteger()) {
//              res.push_back(item.getInteger());
//            } else {
//              flatten(item.getList());
//            }
//          }
//        }
//
//        int next() {
//          return res[i++];
//        }
//
//        bool hasNext() {
//          return i < res.size();
//        }
//    };
}

namespace L198 {
    class Solution {
    public:
        int rob(vector<int> &nums) {
          vector<int> dp;
          for (int i = 0; i < nums.size(); i += 1) {
            if (i == 0) {
              dp.push_back(nums[i]);
            } else if (i == 1) {
              dp.push_back(max(dp[0], nums[i]));
            } else {
              dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
            }
          }
          return dp.back();
        }
    };
}

namespace L213 {
    class Solution {
    public:
        int rob1(vector<int> &nums, int start, int end) {
          vector<int> dp;
          for (int i = start; i < end; i += 1) {
            if (i == start) {
              dp.push_back(nums[i]);
            } else if (i == start + 1) {
              dp.push_back(max(dp[i - start], nums[i]));
            } else {
              dp.push_back(max(dp[i - start - 2] + nums[i], dp[i - start - 1]));
            }
          }
          return dp.back();
        }
        int rob(vector<int> &nums) {
          return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
        }
    };
}

namespace L337 {
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
}

namespace L188 {
    class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
          vector<int> profits;
          int low = 0;
          for (int i = 1; i < prices.size(); i += 1) {
            if (prices[i] < prices[i - 1] && prices[i - 1] > prices[low]) {
              profits.push_back(prices[i - 1] - prices[low]);
              low = i;
            } else if (i == prices.size() - 1 && prices[i] > prices[low]) {
              profits.push_back(prices[i] - prices[low]);
            } else if (prices[i] < prices[low]) {
              low = i;
            }
          }
          sort(profits.begin(), profits.end(), greater<int>());
          int sum = 0;
          for (int i = 0; i < k && i < profits.size() - 1; i += 1) {
            sum += profits[i];
          }
          return sum;
        }
    };
}
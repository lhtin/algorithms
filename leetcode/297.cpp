#include "./leetcode.hpp"

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
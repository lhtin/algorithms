//
// Created by 丁乐华 on 2020/1/15.
//

#ifndef C___LEETCODE_H
#define C___LEETCODE_H

#include "./std.hpp"

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val): val(val), left(nullptr), right(nullptr) {
      
    }
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {

    }
};

#endif //C___LEETCODE_H

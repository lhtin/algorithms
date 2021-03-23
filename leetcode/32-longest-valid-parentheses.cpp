#include "leetcode.hpp"

class Solution {
private:
  class Node {
  public:
    int from;
    int to;
    Node* next;
    Node (int from, int to, Node* next): from(from), to(to), next(next) {}
  };
public:
  int longestValidParentheses(string s) {
    Node* head = nullptr;
    for (int i = 1, len = s.length(); i < len; i += 1) {
      char c = s[i];
      if (c == ')') {
        if (head != nullptr && head->to == i - 1) {
          int from = head->from - 1;
          if (from >= 0 && s[from] == '(') {
            // 增加一层包裹
            head->from = from;
            head->to = i;

            // 检查增加完之后是不是接着上一个，如果是则需要合并
            Node* next = head->next;
            if (next != nullptr && next->to == head->from - 1) {
              head->from = next->from;
              head->next = next->next;
              delete next;
            }
          }
        } else if (s[i - 1] == '(') {
          int to = i;
          int from = i - 1;
          if (head != nullptr && from == head->to + 1) {
            // 跟前一个做比较，如果是接着前一个的，则合并
            head->to = to;
          } else {
            // 否则创建新的最里面一层
            Node* temp = new Node(from, to, head);
            head = temp;
          }
        }
      }
    }
    int max = 0;
    while (head != nullptr) {
      int count = head->to - head->from + 1;
      if (count > max) {
        max = count;
      }
      Node* temp = head;
      head = head->next;
      delete temp;
    }
    return max;
  }
};
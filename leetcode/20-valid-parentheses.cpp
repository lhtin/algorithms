#include "./leetcode.hpp"

class Solution {
public:
  bool isValid(string s) {
    string temp;
    for (int i = 0, len = s.size(); i < len; i += 1) {
      char c = s[i];
      if (c == '(' || c == '{' || c == '[') {
        temp.push_back(c);
      } else {
        int last = temp.size() - 1;
        if (last < 0) {
          return false;
        }
        char last_c = temp[last];
        if (c == ')') {
          if (last_c == '(') {
            temp.pop_back();
          } else {
            return false;
          }
        } else if (c == '}') {
          if (last_c == '{') {
            temp.pop_back();
          } else {
            return false;
          }
        } else if (c == ']') {
          if (last_c == '[') {
            temp.pop_back();
          } else {
            return false;
          }
        }
      }
    }
    if (temp.size() == 0) {
      return true;
    } else {
      return false;
    }
  }
};
#include "leetcode.hpp"

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    int len = strs.size();
    if (len <= 0) {
      return res;
    }
    string& first = strs[0];
    for (int i = 0, len1 = first.size(); i < len1; i += 1) {
      char c = first[i];
      for (int j = 1; j < len; j += 1) {
        string& curr = strs[j];
        if (curr.size() <= i || curr[i] != c) {
          return res;
        }
      }
      res += c;
    }
    return res;
  }
};
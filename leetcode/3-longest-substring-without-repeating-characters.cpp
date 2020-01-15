#include "leetcode.h"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max = 0;
    int len = s.length();
    int start = 0;
    for (int i = 0; i < len; i += 1) {
      int same_i = s.find_first_of(s[i], start);
      if (same_i < i) {
        int sub_len = i - start;
        if (sub_len > max) {
          max = sub_len;
        }
        start = same_i + 1;
      }
    }
    int sub_len = len - start;
    if (sub_len > max) {
      max = sub_len;
    }
    return max;
  }
};
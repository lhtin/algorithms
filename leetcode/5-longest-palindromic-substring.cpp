#include "./leetcode.hpp"

class Solution {
public:
    string longestPalindrome(string s) {
      int l;
      int r;
      int l0 = 0;
      int r0 = 0;
      for (int i = 0; i < s.size(); i += 1) {
        // 奇数回文
        l = i - 1;
        r = i + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
          l--;
          r++;
        }
        if (r - l > r0 - l0) {
          l0 = l;
          r0 = r;
        }
        // cout << "(l, r): " << l << ", " << r << endl;

        // 偶数回文
        l = i;
        r = i + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
          l--;
          r++;
        }
        // cout << "(l, r): " << l << ", " << r << endl;
        if (r - l > r0 - l0) {
          l0 = l;
          r0 = r;
        }
      }
      //   cout << l0 << r0 << endl;
      return s.substr(l0 + 1, r0 - l0 - 1);
    }
};
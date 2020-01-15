#include "leetcode.h"

class Solution {
public:
  string intToRoman(int num) {
    int len = 13;
    int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string res = "";
    for (int i = 0; i < len; i += 1) {
      int count = num / n[i];
      num = num % n[i];
      for (int j = 0; j < count; j += 1) {
        res += s[i];
      }
    }
    return res;
  }
};
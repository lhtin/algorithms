#include "./leetcode.hpp"

class Solution {
public:
    int maxA(int N, int count, int copy) {
      if (N == 0) {
        return count;
      }
      if (N == 1) {
        if (copy > 1) {
          // 粘贴
          return count + copy;
        } else {
          // print A
          return count + 1;
        }
      }
      return max(
          maxA(N - 1, count + 1, copy),
          max(
              maxA(N - 1, count + copy, copy),
              maxA(N - 2, count, count)
              )
          );
    }
    string plus(string a, string b) {
      return "";
    }
    string times(string num, char a) {
      string res = "";
      bool curry = false;
      for (int i = num.size() - 1; i >= 0; i -= 1) {
        int b = (num[i] - '0') * (a - '0');
        cout << num[i] << "," << a << ": " << b << endl;
        res.insert(res.begin(), char((int(b % 10) + (curry ? 1 : 0)) + '0'));
        cout << res << ", " << int(b % 10) + (curry ? 1 : 0) << endl;
        if (b >= 10) {
          curry = true;
        } else {
          curry = false;
        }
      }
      if (curry) {
        res.insert(res.begin(), '1');
      }
      cout << num << "," << a << " res: " << res << endl;
      return res;
    }
    string times(string num1, string num2, int at, string total) {
      if (at >= num2.size()) {
        return total;
      }
      return times(num1, num2, at + 1, plus(total + "0", times(num1, num2[at])));
    }
};
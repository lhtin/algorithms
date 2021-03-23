#include "./std.hpp"

class Solution {
public:
    int min3(int a, int b, int c) {
      return min(a, min(b, c));
    }
    int minDistance(string word1, string word2) {
      vector<vector<int>> dp;
      int n1 = word1.size();
      int n2 = word2.size();
      for (int i = 0; i <= n1; i += 1) {
        dp.push_back(vector<int>(n2 + 1, 0));
        dp[i][0] = i;
      }
      for (int j = 0; j <= n2; j += 1) {
        dp[0][j] = j;
      }
      for (int i = 1; i <= n1; i += 1) {
        for (int j = 1; j <= n2; j += 1) {
          if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            dp[i][j] = min3(
                dp[i - 1][j] + 1, // 选择删除，消耗i
                dp[i - 1][j - 1] + 1, // 选择替换，消耗i和j
                dp[i][j - 1] + 1 // 选择插入，消耗j
            );
          }
        }
      }
      return dp[n1][n2];
    }
};
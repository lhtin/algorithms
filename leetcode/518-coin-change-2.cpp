#include "./leetcode.hpp"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<vector<int>> dp;
      for (int i = 0; i <= coins.size(); i += 1) {
        dp.push_back(vector<int>(amount + 1, 0));
        dp[i][0] = 1;
      }
      for (int i = 1; i <= coins.size(); i += 1) {
        int val = coins[i - 1];
        for (int j = 1; j <= amount; j += 1) {
          if (j - val >= 0) {
            dp[i][j] += dp[i][j - val];
          }
          dp[i][j] += dp[i - 1][j];
        }
      }
      return dp[coins.size()][amount];
    }
};
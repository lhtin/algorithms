#include "./leetcode.hpp"

class Solution {
public:
    int score(vector<int> piles) {
      vector<vector<pair<int, int>>> dp;
      // dp[i][j].first 表示先手从i～j堆石头中可以拿到的石头数量最大值
      // dp[i][j].second 表示后手从i～j堆石头中可以拿到的石头数量最大值
      
      int n = piles.size();
      for (int i = 0; i < n; i += 1) {
        dp.push_back(vector<pair<int, int>>(n, {0, 0}));
        // base case：表示只有一堆石头，则肯定先手拿走，后手为0
        dp[i][i] = {piles[i], 0};
      }
      for (int i = n - 2; i >= 0; i -= 1) {
        for (int j = i + 1; j < n; j += 1) {
          // 先手拿最左边那一堆石头，然后作为后手拿取i+1～j堆石头
          int left = piles[i] + dp[i + 1][j].second;
          // 先手拿最右边那一堆石头，然后作为后手拿取i～j-1堆石头
          int right = dp[i][j - 1].second + piles[j];
          if (left > right) {
            // 如果left大于right，说明先手要拿左边，所以后手作为先手拿取i+1～j中的最大值
            dp[i][j] = {left, dp[i + 1][j].first};
          } else {
            // 后手作为先手拿取i～j-1中的最大值
            dp[i][j] = {right, dp[i][j - 1].first};
          }
        }
      }
      pair<int, int> res = dp[0][n - 1];
      return res.first - res.second;
    }
};
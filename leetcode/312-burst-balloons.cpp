#include "./leetcode.hpp"

class Solution {
public:
    int maxCoins(vector<int>& nums) {
      int size = nums.size() + 2;
      vector<int> points(size);
      points[0] = 1;
      points[size - 1] = 1;
      for (int i = 0; i < nums.size(); i += 1) {
        points[i + 1] = nums[i];
      }
      
      // 初始化dp数组
      // base case: dp[x][x] = 0
      vector<vector<int>> dp;
      for (int i = 0; i < size; i += 1) {
        dp.push_back(vector<int>(size, 0));
      }
      
      // 状态转移：dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[k] * points[j])
      
      // 从下往上
      for (int i = size - 1; i >= 0; i -= 1) {
        // 从左往右
        for (int j = i + 1; j < size; j += 1) {
          // 取(i, j)中的最大值
          for (int k = i + 1; k < j; k += 1) {
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[k] * points[j]);
          }
        }
      }
      return dp[0][size - 1];
    }
};
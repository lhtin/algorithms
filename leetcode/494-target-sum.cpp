#include "./leetcode.hpp"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum < abs(S)) {
        return 0;
      }
      vector<vector<int>> dp;
      for (int i = 0; i <= nums.size(); i += 1) {
        dp.push_back(vector<int>(2 * sum + 1, 0));
      }
      dp[0][0 + sum] = 1;
      for (int i = 1; i <= nums.size(); i += 1) {
        int val = nums[i - 1];
        dp[i][sum] = dp[i - 1][sum - val] + dp[i - 1][sum + val];
        for (int j = 1; j <= sum; j += 1) {
          dp[i][j + sum] = dp[i - 1][j + sum - val];
          dp[i][- j + sum] = dp[i - 1][- j + sum + val];

          if (j + val <= sum) {
            dp[i][j + sum] += dp[i - 1][j + sum + val];
            dp[i][- j + sum] += dp[i - 1][- j + sum - val];
          }
        }
      }
      return dp[nums.size()][S + sum];
    }
};
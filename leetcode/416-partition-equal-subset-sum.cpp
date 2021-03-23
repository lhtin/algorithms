#include "std.hpp"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for (int i = 0; i < nums.size(); i += 1) {
        sum += nums[i];
      }
      if (sum % 2 != 0) {
        return false;
      }
      int target = sum / 2;
      int size = nums.size();
      vector<vector<bool>> dp; // dp[i][j] 表示前i个元素是否可以找出和为j的子集
      for (int i = 0; i <= size; i += 1) {
        dp.push_back(vector<bool>(target + 1, false));
        dp[i][0] = true;
      }
      for (int i = 1; i <= size; i += 1) {
        for (int j = 1; j <= target; j += 1) {
          if (j - nums[i - 1] < 0) {
            dp[i][j] = dp[i - 1][j];
          } else {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
          }
        }
      }
      return dp[size][target];
    }
};
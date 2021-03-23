#include "./leetcode.hpp"

class Solution {
public:
    int rob(vector<int> &nums) {
      vector<int> dp;
      for (int i = 0; i < nums.size(); i += 1) {
        if (i == 0) {
          dp.push_back(nums[i]);
        } else if (i == 1) {
          dp.push_back(max(dp[0], nums[i]));
        } else {
          dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
        }
      }
      return dp.back();
    }
};
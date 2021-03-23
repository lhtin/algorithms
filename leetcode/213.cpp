#include "./leetcode.hpp"

class Solution {
public:
    int rob1(vector<int> &nums, int start, int end) {
      vector<int> dp;
      for (int i = start; i < end; i += 1) {
        if (i == start) {
          dp.push_back(nums[i]);
        } else if (i == start + 1) {
          dp.push_back(max(dp[i - start], nums[i]));
        } else {
          dp.push_back(max(dp[i - start - 2] + nums[i], dp[i - start - 1]));
        }
      }
      return dp.back();
    }
    int rob(vector<int> &nums) {
      return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
    }
};
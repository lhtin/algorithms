#include "leetcode.h"

class Solution {
public:
  // 暴力破解
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int len = nums.size();
    for (int i = 0; i < len; i += 1) {
      int n1 = nums[i];
      for (int j = i + 1; j < len; j += 1) {
        if (n1 + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
};
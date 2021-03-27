#include "./leetcode.hpp"

class Solution {
public:
    int jump(vector<int>& nums) {
      int longest = 0;
      int end = 0;
      int count = 0;
      for (int i = 0; i < nums.size() - 1; i += 1) {
        longest = max(longest, nums[i] + i);
        if (longest >= nums.size() - 1) {
          // 可以一次跳到最后一个位置时再跳一次就可以了
          return count + 1;
        }
        if (end == i) {
          // 到了可跳的最远距离，跟进前面收集到的longest确定下一次跳的最远距离
          count += 1;
          end = longest;
        }
      }
      return count;
    }
};
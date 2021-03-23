#include "./std.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> levelList;
      levelList.push_back(nums[0]);
      for (int i = 1; i < nums.size(); i += 1) {
        int val = nums[i];
        int left = 0;
        int right = levelList.size() - 1;
        do {
          int mid = left + (right - left) / 2;
          int min = levelList[mid];
          if (min < val) {
            left = mid + 1;
          } else if (min >= val) {
            right = mid - 1;
          }
        } while(left <= right);

        if (left >= levelList.size()) {
          levelList.push_back(val);
        } else {
          levelList[left] = nums[i];
        }
      }
      return levelList.size();
    }
};
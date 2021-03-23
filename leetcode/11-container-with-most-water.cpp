#include "leetcode.hpp"

class Solution {
public:
  int maxArea(vector<int>& height) {
    int len = height.size();
    int max = 0;
    for (int i = 0; i < len; i += 1) {
      for (int j = i + 1; j < len; j += 1) {
        int temp = (j - i) * min(height[i], height[j]);
        if (temp > max) {
          max = temp;
        }
      }
    }
    return max;
  }
};
#include "./leetcode.hpp"

class Solution {
public:
    int trap(vector<int>& height) {
      if (height.size() == 0) {
        return 0;
      }
      int max = 0;
      for (int i = 0; i < height.size(); i += 1) {
        if (height[i] > height[max]) {
          max = i;
        }
      }
      int area = 0;
      
      int gray = 0;
      int temp = 0;
      for (int i = 0; i <= max; i += 1) {
        int h = height[i];
        if (h >= temp) {
          area += gray;
          gray = 0;
          temp = h;
        } else {
          gray += temp - h;
        }
      }
      
      gray = 0;
      temp = 0;
      for (int i = height.size() - 1; i >= max; i -= 1) {
        int h = height[i];
        if (h >= temp) {
          area += gray;
          gray = 0;
          temp = h;
        } else {
          gray += temp - h;
        }
      }
      return area;
    }
};
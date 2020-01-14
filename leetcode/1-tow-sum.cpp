/**
 * https://leetcode-cn.com/problems/two-sum/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // 暴力破解
  vector<int> twoSum1(vector<int>& nums, int target) {
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

  // 从已排序的数组中寻找两个数之和等于给定值
  vector<int> twoSumInSorted(vector<int>& nums, int target) {
    vector<int> result;
    // 首尾指针往中间移动
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      int sum = nums[i] + nums[j];
      if (sum < target) {
        i += 1;
      } else if (sum > target) {
        j -= 1;
      } else {
        result.push_back(nums[i]);
        result.push_back(nums[j]);
        break;
      }
    }
    return result;
  }
};

int main () {
  Solution s;
  vector<int> nums({1, 2, 10, 7, 8, 11, 15});
  int target = 9;
  vector<int> result = s.twoSum1(nums, target);

  cout << result[0] << ", " << result[1] << endl;

  return 0;
}
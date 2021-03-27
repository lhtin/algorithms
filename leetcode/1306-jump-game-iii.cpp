#include "./leetcode.hpp"

class Solution {
private:
    unordered_map<int, int> dp;
public:
    int canReach0(vector<int>& arr, int start) {
      if (start < 0 || start >= arr.size()) {
        return 0;
      }
      if (arr[start] == 0) {
        return 1;
      }
      
      if (dp.count(start)) {
        if (dp[start] == -1) {
          // 为-1表示循环了
          return 0;
        }
        return dp[start];
      }
      dp[start] = -1;
      dp[start] = canReach0(arr, start + arr[start]) || canReach0(arr, start - arr[start]);
      return dp[start];
    }
    bool canReach(vector<int>& arr, int start) {
      return canReach0(arr, start) == 1;
    }
};
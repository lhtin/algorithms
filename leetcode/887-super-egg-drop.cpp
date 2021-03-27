#include "./leetcode.hpp"

class Solution {
public:
    int superEggDrop(int K, int N) {
      vector<vector<int>> dp;
      // dp[0][...] = 0
      // dp[...][0] = 0
      for (int k = 0; k <= K; k += 1) {
        dp.push_back(vector<int>(N + 1, 0));
      }
      
      // dp[k][m] 表示k个鸡蛋扔m次，最多可以扔多少层楼
      // dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1
      //   dp[k][m - 1] 表示扔了一次但是没有碎之后可以再扔多少层楼（即i之下的楼层数量）
      //   dp[k - 1][m - 1] 表示扔了一次但是碎了之后可以再扔多少层楼（即i之上的楼层数量）

      int m = 0;
      while(dp[K][m] < N) {
        m++;
        for (int k = 1; k <= K; k++) {
          dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
        }
      }
      return m;
    }
};

//class Solution2 {
//private:
//    map<pair<int, int>, int> cache;
//public:
//    int superEggDrop(int k, int n) {
//      if (k == 1) {
//        return n;
//      }
//      if (n == 0) {
//        return 0;
//      }
//      if (cache.count(pair<int, int>(k, n))) {
//        return cache[pair<int, int>(k, n)];
//      }
//      int res = INT_MAX;
//      for (int i = 1; i <= n; i += 1) {
//        // 一层层楼开始试，取最小的
//        res = min(res, max(superEggDrop(k - 1, i - 1), superEggDrop(k, n - i)) + 1);
//      }
//      cache[pair<int, int>(k, n)] = res;
//      return res;
//
//    }
//};
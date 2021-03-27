#include <iostream>
#include <vector>
using namespace std;

int main() {
  int total;
  int count;
  vector<int> v;
  vector<int> w;
  vector<vector<int>> dp;

  // 1. 收集数据
  cin >> total >> count;
  for (int i = 0; i < count; i++) {
    int price, weight;
    cin >> price >> weight;
    v.push_back(price);
    w.push_back(weight);
  }
  
  // dp[i][j] 表示在前j个物品中选择不超过i的最大价值
  // 2. 初始化
  // base case：
  //   dp[0][...] = 0
  //   dp[...][0] = 0
  for (int i = 0; i <= total; i++) {
    dp.emplace_back(count + 1, 0);
  }
  
  // 3. 状态转移
  for (int i = 1; i <= total; i++) {
    for (int j = 1; j <= count; j++) {
      int price = v[j - 1];
      int weight = w[j - 1];
      if (i >= price) {
        // 选择第j个物品
        dp[i][j] = max(dp[i][j], dp[i - price][j - 1] + price * weight);
      } else {
        // 不选第j个物品
        dp[i][j] = dp[i][j - 1];
      }
    }
  }
  cout << dp[total][count] << endl;
}
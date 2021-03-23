class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      vector<int> profits;
      int low = 0;
      for (int i = 1; i < prices.size(); i += 1) {
        if (prices[i] < prices[i - 1] && prices[i - 1] > prices[low]) {
          profits.push_back(prices[i - 1] - prices[low]);
          low = i;
        } else if (i == prices.size() - 1 && prices[i] > prices[low]) {
          profits.push_back(prices[i] - prices[low]);
        } else if (prices[i] < prices[low]) {
          low = i;
        }
      }
      sort(profits.begin(), profits.end(), greater<int>());
      int sum = 0;
      for (int i = 0; i < k && i < profits.size() - 1; i += 1) {
        sum += profits[i];
      }
      return sum;
    }
};
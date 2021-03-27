#include "./leetcode.hpp"

class Solution {
private:
    unordered_map<int, vector<int>> sameMap;
    unordered_map<int, int> dp;
    vector<int> steps;
    unordered_set<int> a;
public:
    int minJumps(vector<int>& arr) {
      for (int i = 0; i < arr.size(); i += 1) {
        if (sameMap.count(arr[i])) {
          sameMap[arr[i]].push_back(i);
        } else {
          sameMap[arr[i]] = vector<int>(1, i);
        }
        steps.push_back(INT_MAX);
      }
      steps[0] = 0;
      a.insert(0);
      // 一次前进一步
      while(!a.empty()) {
        unordered_set<int> b;
        for (int i : a) {
          cout << i << ", " << endl;
          if (i > 0 && steps[i] + 1 < steps[i - 1]) {
            steps[i - 1] = steps[i] + 1;
            if (steps[arr.size() - 1] < INT_MAX) {
              return steps[arr.size() - 1];
            }
            b.insert(i - 1);
          }
          if (i < arr.size() - 1 && steps[i] + 1 < steps[i + 1]) {
            steps[i + 1] = steps[i] + 1;
            if (steps[arr.size() - 1] < INT_MAX) {
              return steps[arr.size() - 1];
            }
            b.insert(i + 1);
          }
          // 使用一次就可以去掉了
          vector<int> same = sameMap[arr[i]];
          for (int j = 0; j < same.size(); j += 1) {
            int at = same[j];
            if (steps[i] + 1 < steps[at]) {
              steps[at] = steps[i] + 1;
              if (steps[arr.size() - 1] < INT_MAX) {
                return steps[arr.size() - 1];
              }
              b.insert(at);
            }
          }
          sameMap[arr[i]] = vector<int>(0);
        }
        a = b;
      }
      return steps[arr.size() - 1];
    }
    void minJumps(vector<int>& arr, int at, int step) {
      if (at < 0 || at >= arr.size()) {
        return;
      }
      if (steps[at] <= step) {
        return;
      }
      steps[at] = step;
      minJumps(arr, at + 1, step + 1);
      minJumps(arr, at - 1, step + 1);
      vector<int> same = sameMap[arr[at]];
      for (int i = 0; i < same.size(); i += 1) {
        int j = same[i];
        minJumps(arr, j, step + 1);
      }
    }
};
#include "./leetcode.hpp"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
      map<pair<int, int>, int> dp;
      set<pair<int, int>> points;
      int minX = INT_MAX;
      int maxX = INT_MIN;
      int minY = INT_MAX;
      int maxY = INT_MIN;
      int area = 0;
      for (auto rectangle : rectangles) {
        minX = min(minX, rectangle[0]);
        minY = min(minY, rectangle[1]);
        maxX = max(maxX, rectangle[2]);
        maxY = max(maxY, rectangle[3]);
        area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
        pair<int, int> p1 = {rectangle[0], rectangle[1]};
        pair<int, int> p2 = {rectangle[2], rectangle[1]};
        pair<int, int> p3 = {rectangle[0], rectangle[3]};
        pair<int, int> p4 = {rectangle[2], rectangle[3]};
        if (points.count(p1)) {
          points.erase(p1);
        } else {
          points.insert(p1);
        }
        if (points.count(p2)) {
          points.erase(p2);
        } else {
          points.insert(p2);
        }
        if (points.count(p3)) {
          points.erase(p3);
        } else {
          points.insert(p3);
        }
        if (points.count(p4)) {
          points.erase(p4);
        } else {
          points.insert(p4);
        }
      }
      if (area != (maxX - minX) * (maxY - minY) || 
          points.size() != 4 ||
          !(points.count({minX, minY}) && points.count({maxX, minY}) && points.count({minX, maxY}) && points.count({maxX, maxY}))) {
        return false;
      }
      
      return true;
    }
};


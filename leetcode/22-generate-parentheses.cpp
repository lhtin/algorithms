#include "leetcode.h"

class Solution {
public:
  vector<string>* _gen (string pre, int l, int r, int n) {
    vector<string>* res = new vector<string>;
    if (l == n && r == n) {
      res->push_back(pre);
      return res;
    }
    if (l < n) {
      vector<string>* temp = _gen(pre + "(", l + 1, r, n);
      res->insert(
          res->end(),
          make_move_iterator(temp->begin()),
          make_move_iterator(temp->end()));
    }
    if (r < l) {
      vector<string>* temp = _gen(pre + ")", l, r + 1, n);
      res->insert(
          res->end(),
          make_move_iterator(temp->begin()),
          make_move_iterator(temp->end()));
    }
    return res;
  }
  vector<string> generateParenthesis(int n) {
    return *_gen("", 0, 0, n);
  }
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) {
      return head;
    }
    int count = 0;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* start = nullptr;
    ListNode* end = nullptr;
    while (curr != nullptr) {
      count += 1;
      if (count == 1) {
        start = curr;
      }
      if (count == k) {
        end = curr;
        curr = curr->next;
        ListNode* next = end->next;
        ListNode* curr1 = start;
        // 反转
        while (true) {
          ListNode* temp = curr1->next;
          curr1->next = next;
          if (curr1 == end) {
            break;
          }
          next = curr1;
          curr1 = temp;
        }
        if (prev == nullptr) {
          head = end;
          prev = start;
        } else {
          prev->next = end;
          prev = start;
        }
        count = 0;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
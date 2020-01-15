struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* prev = head;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 == nullptr) {
        if (head == nullptr) {
          head = l2;
          break;
        } else {
          prev->next = l2;
          break;
        }
      } else if (l2 == nullptr) {
        if (head == nullptr) {
          head = l1;
          break;
        } else {
          prev->next = l1;
          break;
        }
      }

      ListNode* selected = nullptr;
      if (l1->val <= l2->val) {
        selected = l1;
        l1 = l1->next;
      } else {
        selected = l2;
        l2 = l2->next;
      }
      if (head == nullptr) {
        head = selected;
        prev = head;
      } else {
        prev->next = selected;
        prev = selected;
      }
    }
    return head;
  }
};
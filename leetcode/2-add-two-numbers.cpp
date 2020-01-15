struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
      int sum = carry;
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      if (sum > 9) {
        carry = 1;
        sum = sum % 10;
      } else {
        carry = 0;
      }
      ListNode* node = new ListNode(sum);
      if (head == nullptr) {
        head = node;
        curr = head;
      } else {
        curr->next = node;
        curr = curr->next;
      }
    }
    if (carry > 0) {
      ListNode* node = new ListNode(carry);
      curr->next = node;
    }
    return head;
  }
};
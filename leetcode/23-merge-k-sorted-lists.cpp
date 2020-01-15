struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct Node {
  ListNode* val;
  Node* next;
  Node(ListNode* x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = nullptr;
    ListNode* prev = head;
    Node* temp_head = nullptr;
    Node* temp_prev = temp_head;
    for (int i = 0, len = lists.size(); i < len; i += 1) {
      ListNode* head = lists[i];
      if (head != nullptr) {
        Node* item = new Node(head);
        if (temp_head == nullptr) {
          temp_head = item;
          temp_prev = temp_head;
        } else {
          temp_prev->next = item;
          temp_prev = item;
        }
      }
    }
    while (true) {
      ListNode* selected = nullptr;
      Node* selected_prev = nullptr;
      Node* temp_prev = nullptr;
      Node* curr = temp_head;
      while (curr != nullptr) {
        ListNode* item = curr->val;
        if (selected == nullptr || item->val < selected->val) {
          selected = item;
          selected_prev = temp_prev;
        }
        temp_prev = curr;
        curr = curr->next;
      }
      if (selected == nullptr) {
        break;
      }

      if (selected->next == nullptr) {
        if (selected_prev == nullptr) {
          temp_head = temp_head->next;
        } else {
          selected_prev->next = selected_prev->next->next;
        }
      } else {
        if (selected_prev == nullptr) {
          temp_head->val = selected->next;
        } else {
          selected_prev->next->val = selected->next;
        }
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
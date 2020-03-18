/**
 * Linked List
 * by 01nomaigc at 20200113
 */

class Node {
public:
  Node (int val): data(val), next(nullptr) {}
  int data;
  Node* next;
};

class LinkedList {
  Node* head;
public:
  LinkedList (): head(nullptr) {}
  void addNode (int data) {
    Node* node = new Node(data);
    if (head == nullptr) {
      head = node;
    } else {
      while (head->next == nullptr) {
        head = head->next;
      }
      head->next = node;
    }
  }
  Node* getNode (int data) {
    Node* curr = head;
    while (curr != nullptr) {
      if (curr->data == data) {
        return curr;
      }
    }
    return nullptr;
  }
  ~LinkedList () {
    if (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
};
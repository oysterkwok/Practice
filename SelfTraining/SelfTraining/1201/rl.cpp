#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *add(ListNode *head, int num) {
  ListNode *ptr = new ListNode(num);
  ptr->next = head;
  return ptr;
}

void print(ListNode *head) {
  cout << '{';
  while (head != NULL) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << '}' << '\n';
}

ListNode *add_back(ListNode *head, int num) {
  if (head != NULL) {
    head->next = add_back(head->next, num);
    return head;
  }
  else {
    head = new ListNode(num);
    return head;
  }
}

ListNode *reverse(ListNode *head) {
  if (head == NULL) {
    return NULL;
  else {
    ListNode *node = head->val;
    node->next = 
  }
}

void reorderList(ListNode *head) {
  head->next = reverse(head->next)
  reorderList(head->next);
}


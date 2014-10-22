#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

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

void print(ListNode *head) {
  cout << '{';
  while (head != NULL) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << "}\n";
}

ListNode *islhelper(ListNode *result, int num) {
  if (result == NULL) {
    return new ListNode(num);
  }
  else if (result->val < num) {
    result->next = islhelper(result->next, num);
    return result;
  }
  else {
    ListNode *new_node = new ListNode(num);
    new_node->next = result;
    return new_node;
  }
}

ListNode *insertionSortList(ListNode *head) {
  ListNode *result = NULL;
  while (head != NULL) {
    result = islhelper(result, head->val);
    head = head->next;
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    ListNode *head = NULL;
    for (int i = 0; i < n; i ++) {
      int num;
      cin >> num;
      head = add_back(head, num);
    }
    print(head);
    ListNode *isl = insertionSortList(head);
    print(isl);
    cin >> n;
  }
}


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

ListNode *sortList(ListNode *head) {
  if (head == NULL) {
    return NULL;
  }
  int mid = head->val;
  head = head->next;
  ListNode *left = NULL;
  ListNode *right = NULL;
  while (head != NULL) {
    if (head->val < mid) {
      left = add(left, head->val);
    }
    else {
      right = add(right, head->val);
    }
    head = head->next;
  }

  left = sortList(left);
  right = sortList(right);

  head = NULL;
  while (left != NULL) {
    head = add_back(head, left->val);
    left = left->next;
  }
  head = add_back(head, mid);
  while (right != NULL) {
    head = add_back(head, right->val);
    right = right->next;
  }
  return head;
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
    ListNode *sl = sortList(head);
    print(sl);
    cin >> n;
  }
}

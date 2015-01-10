#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int d): val(d), next(NULL) {}
  void add_node(int d) {
    ListNode *new_node = new ListNode(d);
    ListNode *cur_node = this;
    while (cur_node->next != NULL)
      cur_node = cur_node->next;
    cur_node->next = new_node;
  }

  void print() {
    ListNode *cur_node = this;
    while (cur_node != NULL) {
      cout << cur_node->val << " ";
      cur_node = cur_node->next;
    }
    cout << endl;
  }

  int length() {
    ListNode *cur_node = this;
    int count = 1;
    while (cur_node != NULL) {
      cur_node = cur_node->next;
      count++;
    }
    return count;
  }
};

ListNode *add_list_helper(ListNode *l1, ListNode *l2, int &carry) {
  if (l1 == NULL && l2 == NULL)
    return NULL;

  int cur_carry = 0;
  ListNode *remain_node = add_list_helper(l1 == NULL? NULL: l1->next,
                                          l2 == NULL? NULL: l2->next,
                                          cur_carry);
  int num1 = 0;
  if (l1 != NULL)
    num1 = l1->val;
  int num2 = 0;
  if (l2 != NULL)
    num2 = l2->val;

  int cur_val = (num1 + num2 + cur_carry) % 10;
  carry = (num1 + num2 + cur_carry) / 10;
  ListNode *val_node = new ListNode(cur_val);
  val_node->next = remain_node;

  return val_node;
}

ListNode *add_zero_node_before_head(ListNode *head, int count) {
  for (int i = 0; i < count; ++i) {
    ListNode *temp = new ListNode(0);
    temp->next = head;
    head = temp;
  }
  return head;
}

ListNode *add_list(ListNode *l1, ListNode *l2) {
  // 要让两个list等长度
  // 向l1和l2之前填充0
  int len1 = l1->length();
  int len2 = l2->length();
  if (len1 < len2) {
    l1 = add_zero_node_before_head(l1, len2 - len1);
  }
  if (len1 > len2) {
    l2 = add_zero_node_before_head(l2, len1 - len2);
  }
  l1->print();
  l2->print();
  int cur_carry = 0;
  ListNode *head = add_list_helper(l1, l2, cur_carry);
  if (cur_carry != 0) {
    ListNode *temp = new ListNode(cur_carry);
    temp->next = head;
    head = temp;
  }
  return head;
}

ListNode *generate_list(const int length) {
  ListNode *head = NULL;
  /* initialize random seed: */
  srand (time(NULL));
  for (int i = 0; i < length; ++i)
  {
    if (head == NULL)
      head = new ListNode(rand() % 9 + 1);
    else
      head->add_node(rand() % 9 + 1);
  }
  return head;
}

int main()
{
  ListNode *l1 = generate_list(5);
  ListNode *l2 = generate_list(2);
  ListNode *head = add_list(l1, l2);
  head->print();
  return 0;
}

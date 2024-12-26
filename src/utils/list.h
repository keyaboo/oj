// tree.h
#include <vector>
#include <queue>
#include <iostream>

#ifndef LIST_H
#define LIST_H

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createListFromValues(const std::vector<int>& values);

void deleteList(ListNode* head);

void printList(ListNode* head);

#endif
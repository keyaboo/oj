#include <bits/stdc++.h> 
#include "list.h"
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
ListNode* reverseList(ListNode* head);

int main() {
    fast; 
    int t = 3;  
    string line;
    while(t--) {
        getline(cin, line);
        string temp;
        stringstream ss(line.substr(1, line.size() - 2));
        vector<int> values;
        while (getline(ss, temp, ',')) {
            values.push_back(stoi(temp));
        }
        ListNode* head = createListFromValues(values);
        ListNode* rev = reverseList(head);
        printList(rev);
        deleteList(rev);
    }
    return 0;
}

ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL; // I guess you need to specify this explicitly in C++
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } 
    return prev;
}


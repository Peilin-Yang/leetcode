#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* insert(ListNode* l, int x){
    ListNode *n = new ListNode(x);
    n->next = l;
    return n;
}


void print(ListNode* l){
    cout << l->val;
    while(l->next != NULL){
        cout << "->";
        l = l->next;
        cout << l->val;
    }
    cout << endl; 
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *first_bigger = head->val>=x?head:head->next;
        ListNode *pre, *new_head;
        if(first_bigger==head) {
            pre = new ListNode(0);
            pre->next = head;
        } else {
            pre = head;
        }
        new_head = pre;
        while (first_bigger && first_bigger->val < x) {
            pre = pre->next;
            first_bigger = first_bigger->next;
        }
        ListNode *cur = pre;
        while (first_bigger) {
            if (first_bigger->val < x) {
                ListNode *n2 = first_bigger->next;
                ListNode *n1 = pre->next;
                pre->next = first_bigger;
                pre->next->next = n1;
                first_bigger = n2;
                pre = pre->next;
                cur->next = first_bigger;
                continue;
            }
            cur = first_bigger;
            first_bigger = first_bigger->next;
        }
        return new_head==head?head:new_head->next;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(1);
    l1 = insert(l1, 1);
    print(l1);
    ListNode* r = s->partition(l1, 0);
    print(r);

    return 0;
}


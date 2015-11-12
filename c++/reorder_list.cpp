#include <iostream>
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
    ListNode *reverse(ListNode* head) {
       if (!head || !head->next) return head;
       ListNode *prev = head, *cur = head->next, *n = NULL;
       while (cur) {
           n = cur->next;
           cur->next = prev;
           prev = cur;
           cur = n;
       }
       head->next = NULL;
       return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *slow_next = slow->next;
        ListNode *r = reverse(slow_next);
        slow->next = NULL;
        print(r);
        ListNode *cur = head;
        while (cur && r) {
            ListNode *n1 = cur->next, *n2 = r->next;
            cur->next = r;
            r->next = n1;
            cur = n1;
            r = n2;
        }
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l = new ListNode(4);
    l = insert(l, 3);
    l = insert(l, 2);
    l = insert(l, 1);
    cout << "original: ";
    print(l);
    //ListNode* r = s->reverseKListNode(l1, 3);
    s->reorderList(l);
    cout << "after sort: ";
    print(l);
    return 0;
}


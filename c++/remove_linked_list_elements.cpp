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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode *n = cur->next->next;
                cur->next = NULL;
                cur->next = n;
            } else {
                cur = cur->next;
            }
        } 
        return dummy->next;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l = new ListNode(6);
    l = insert(l, 6);
    l = insert(l, 6);
    l = insert(l, 6);
    l = insert(l, 6);
    l = insert(l, 6);
    l = insert(l, 6);
    l = insert(l, 1);
    cout << "original: ";
    print(l);
    //ListNode* r = s->reverseKListNode(l1, 3);
    ListNode* r= s->removeElements(l, 6);
    cout << "after sort: ";
    print(r);
    return 0;
}


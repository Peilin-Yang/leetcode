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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *cur = head, *new_head = head, *nxt = head->next;
        while (nxt) {
            if (nxt->val != cur->val) {
                cur->next = nxt;
                cur = nxt;
            }
            nxt = nxt->next;
        }
        cur->next = nxt;
        return new_head;
    }
};


int main(){
    Solution *s = new Solution();
    ListNode *l = new ListNode(3);
    l = insert(l, 3);
    l = insert(l, 3);
    l = insert(l, 2);
    l = insert(l, 1);
    l = insert(l, 1);
    ListNode* r = s->deleteDuplicates(l);
    print(r);
    return 0;
}

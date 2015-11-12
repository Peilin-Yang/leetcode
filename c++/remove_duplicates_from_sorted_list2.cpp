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
        ListNode *new_head = new ListNode(0), *cur = head, *nxt = head->next;
        ListNode *pre = new_head;
        while (nxt) {
            if (nxt->val != cur->val) {
                if (cur->next != nxt) {
                    
                } else {
                    pre->next = cur;
                    pre = cur;
                }
                cur = nxt;
            }
            nxt = nxt->next;
        }
        pre->next = cur->next?NULL:cur;
        return new_head->next;
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

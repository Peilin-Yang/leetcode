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
    ListNode* insert(ListNode* r, int val) {
        if (r == NULL) {
            r = new ListNode(val);
        } else {
            ListNode* tmp = new ListNode(val);
            r->next = tmp;
            r = tmp;
        }
        return r;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* r = NULL;
        ListNode* h = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    r = insert(r, l1->val);
                    if (h == NULL) {
                        h = r;
                    }
                    l1 = l1->next;
                } else {
                    r = insert(r, l2->val);
                    if (h == NULL) {
                        h = r;
                    }
                    l2 = l2->next;
                }
            } else {
                if (l1 != NULL) {
                    r = insert(r, l1->val);
                    if (h == NULL) {
                        h = r;
                    }
                    l1 = l1->next;
                } else {
                    r = insert(r, l2->val);
                    if (h == NULL) {
                        h = r;
                    }
                    l2 = l2->next;
                }
            }
        }
        return h;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);
    //l1 = insert(l1, 2);
    //l1 = insert(l1, 3);
    //l1 = insert(l1, 2);
    //l1 = insert(l1, 1);
    print(l1);
    print(l2);
    ListNode* r = s->mergeTwoLists(l1, l2);
    print(r);
    return 0;
}

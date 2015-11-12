#include<iostream>

using namespace std;



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = NULL;
        ListNode* cur = NULL;
        while(l1 || l2) {
            if (l1 != NULL && l2 == NULL) {
                ListNode *tmp = new ListNode(l1->val);
                if (ret == NULL) {
                   ret = tmp;
                   cur = tmp;
                } else {
                   cur->next = tmp;
                   cur = tmp;
                }
                l1 = l1->next;
            } else if (l1 == NULL && l2 != NULL) {
                ListNode *tmp = new ListNode(l2->val);
                if (ret == NULL) {
                   ret = tmp;
                   cur = tmp;
                } else {
                   cur->next = tmp;
                   cur = tmp;
                }
                l2 = l2->next;
            } else {
                ListNode *tmp = NULL;
                if (l1->val <= l2->val) {
                    tmp = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    tmp = new ListNode(l2->val);
                    l2 = l2->next;
                }
                if (ret == NULL) {
                   ret = tmp;
                   cur = tmp;
                } else {
                   cur->next = tmp;
                   cur = tmp;
                }
            }
        }
        return ret;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(2);
    //l1 = insert(l1, 4);
    //l1 = insert(l1, 3);
    print(l1);
    ListNode *l2 = new ListNode(1);
    //l2 = insert(l2, 6);
    //l2 = insert(l2, 4);
    print(l2);
    ListNode* r = s->mergeTwoLists(l1, l2);
    print(r);
    return 0;
}

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode* r = NULL;
        ListNode* re = NULL;
        while (l1 != NULL || l2 != NULL) {
            int this_digit = 0;
            if (l1 != NULL) {
                this_digit += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                this_digit += l2->val;
                l2 = l2->next;
            }
            int this_r = this_digit+carry;
            carry = this_r/10;
            ListNode* this_l = new ListNode(this_r%10);
            if (r == NULL) {
                r = this_l;
                re = r;
            } else {
                r->next = this_l;
                r = this_l;
            }
        }

        if (carry > 0) {
            ListNode* this_l = new ListNode(carry);
            if (r == NULL) {
                r = this_l;
                re = r;
            } else {
                r->next = this_l;
                r = this_l;
            } 
        }

        return re;
    }
};


int main(){
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(5);
    l1 = insert(l1, 4);
    l1 = insert(l1, 3);
    print(l1);
    ListNode *l2 = new ListNode(5);
    l2 = insert(l2, 6);
    l2 = insert(l2, 4);
    print(l2);
    ListNode* r = s->addTwoNumbers(l1, l2);
    print(r);
    return 0;
}

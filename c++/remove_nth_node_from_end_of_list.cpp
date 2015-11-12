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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* tmp_head = head;
        ListNode* f0 = NULL, *f1 = NULL, *f2 = head;
        while (f2 != NULL) {
            f2 = f2->next;
            n--;
            if (n <= 0) {
                if (f1 == NULL) {
                    f1 = head;
                } else {
                    f1 = f1->next;
                }
            }
            if (n <= -1) {
                if (f0 == NULL) {
                    f0 = head;
                } else {
                    f0 = f0->next;
                }
            }
        }
        if (f0 == NULL) {
            cout << f0 << f1 << endl;
            return f1->next;
        } else {
            f0->next = f1->next;
        }
        return tmp_head;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(1);
    //l1 = insert(l1, 4);
    //l1 = insert(l1, 3);
    //l1 = insert(l1, 2);
    //l1 = insert(l1, 1);
    print(l1);
    ListNode* r = s->removeNthFromEnd(l1, 1);
    print(r);
    return 0;
}

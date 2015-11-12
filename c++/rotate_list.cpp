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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode *tail = head;
        ListNode *new_head = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len;
        if (k) {
            for (int i = 0; i < len-k; i++) {
                tail = tail->next;
            }
        }
        new_head = tail->next;
        tail->next = NULL;
        return new_head;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(1);
    l1 = insert(l1, 4);
    l1 = insert(l1, 3);
    l1 = insert(l1, 2);
    l1 = insert(l1, 1);
    print(l1);
    ListNode* r = s->rotateRight(l1, 2);
    print(r);
    return 0;
}

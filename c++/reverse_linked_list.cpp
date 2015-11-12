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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(4);
    l1 = insert(l1, 2);
    l1 = insert(l1, 3);
    cout << "original: ";
    print(l1);
    //ListNode* r = s->reverseKListNode(l1, 3);
    ListNode* r = s->reverseList(l1);
    cout << "after reverse: ";
    print(r);
    return 0;
}


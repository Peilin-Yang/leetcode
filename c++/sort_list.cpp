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
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *e = dummy;
        while (l1 || l2) {
            if (l1 && (l2 == NULL || l1->val <= l2->val)) {
                e->next = l1;
                e = e->next;
                l1 = l1->next;
            }
            if (l2 && (l1 == NULL || l2->val < l1->val)) {
                e->next = l2;
                e = e->next;
                l2 = l2->next;
            }
        }
        e->next = NULL;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *fast = head->next, *slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *nd = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(nd));
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
    ListNode* r = s->sortList(l1);
    cout << "after sort: ";
    print(r);
    return 0;
}


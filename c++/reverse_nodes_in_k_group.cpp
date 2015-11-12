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
    ListNode* reverseKListNode(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode *prev = head, *l = head->next, *next = NULL;
        while (--k > 0 && l != NULL) {
            next = l->next;
            l->next = prev;
            prev = l;
            l = next;
        }
        head->next = NULL;
        print(prev);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *l = head, *prepre = NULL, *new_head = NULL;
        int cnt = 1;
        while (l != NULL) {
            l = l->next;
            cnt++;
            if (cnt == k && l != NULL) {
                ListNode *next = l->next;
                if (new_head == NULL) {
                    ListNode *r = reverseKListNode(head, k);
                    new_head = r;
                    prepre = head;
                    prepre->next = next;
                } else {
                    ListNode *pre_next = prepre->next;
                    ListNode *r = reverseKListNode(pre_next, k);
                    prepre->next = r;
                    pre_next->next = next;
                    prepre = pre_next;
                }
                l = next;
                cnt = 1;
            }
        }
        if (new_head == NULL) return head;
        return new_head;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(5);
    l1 = insert(l1, 4);
    l1 = insert(l1, 3);
    l1 = insert(l1, 2);
    l1 = insert(l1, 1);
    cout << "original: ";
    print(l1);
    //ListNode* r = s->reverseKListNode(l1, 3);
    ListNode* r = s->reverseKGroup(l1, 2);
    cout << "after reverse: ";
    print(r);
    return 0;
}


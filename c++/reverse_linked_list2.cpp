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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt = n-m+1;
        ListNode *prev = NULL, *cur = head, *nt = NULL, *prepre;
        int idx = 1;
        while (idx < m-1 && cur) {
            cur = cur->next;
            idx++;
        }
        if (!cur || !cur->next) return head;
        if (m == 1) {
            prepre = NULL;
            prev = cur;
            cur = cur->next;
        } else {
            prepre = cur;
            prev = cur->next;
            cur = cur->next->next;
        }
        while (--cnt && cur) {
            nt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nt;
        }
        if (prepre) {
            ListNode *pre_next = prepre->next;
            prepre->next = prev;
            pre_next->next = cur;
        } else {
            head->next = cur;
        }
        return m == 1?prev:head;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l = new ListNode(5);
    l = insert(l, 4);
    l = insert(l, 3);
    l = insert(l, 2);
    l = insert(l, 1);
    print(l);
    ListNode* r = s->reverseBetween(l,1,1);
    print(r);

    return 0;
}


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
    ListNode *swapPairs(ListNode *head) {
        ListNode *new_head = NULL, *pre = NULL, *prepre = NULL;
        ListNode *l = head;
        int k = 1;
        int cnt = k;
        while (l != NULL) {
            l = l->next;
            if (pre != NULL) pre = pre->next;
            cnt--;
            if (cnt == 0 && l != NULL) {
                if (new_head == NULL) {
                    new_head = l;
                    pre = head;
                    prepre = head;
                    prepre->next = l->next;
	            l->next = head;
                    l = prepre->next;
                } else {
                    prepre->next = l;
                    pre->next = l->next;
		    l->next = pre;
		    prepre = pre;
		    l = pre->next;
                }
                cnt = k;
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
    print(l1);
    ListNode* r = s->swapPairs(l1);
    print(r);

    l1 = new ListNode(2);
    l1 = insert(l1, 2);
    l1 = insert(l1, 6);
    l1 = insert(l1, 4);
    l1 = insert(l1, 3);
    l1 = insert(l1, 5);
    l1 = insert(l1, 2);
    print(l1);
    r = s->swapPairs(l1);
    print(r);

    l1 = new ListNode(1);
    print(l1);
    r = s->swapPairs(l1);
    print(r);
    return 0;
}


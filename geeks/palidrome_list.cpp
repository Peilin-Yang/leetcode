#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    char val;
    ListNode *next;
    ListNode(char x) : val(x), next(NULL) {}
};


ListNode* insert(ListNode* l, char x){
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
    ListNode *r(ListNode *l) {
        if (!l || !l->next) return l;
        ListNode *prev=l, *cur=l->next, *n=NULL;
        while (cur) {
            n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        l->next = NULL;
        return prev;
    }
    bool palidrome_list(ListNode *l) {
        if (!l || !l->next) return true;
        ListNode *fast = l->next, *slow = l;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *slow_next = slow->next;
        slow->next = NULL;
        ListNode *re = r(slow_next);
        while (re && l) {
            if (re->val == l->val) {
                re = re->next;
                l = l->next;
            } else return false;
        }
        return (re && !re->next) || (l && !l->next) || (!re && !l);
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l = new ListNode('a');
    l = insert(l, 'b');
    l = insert(l, 'b');
    l = insert(l, 'a');
    cout << "original: ";
    print(l);
    cout << std::boolalpha << s->palidrome_list(l) << endl;
    return 0;
}


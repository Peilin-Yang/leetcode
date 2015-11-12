#include <iostream>
#include <vector>
#include <queue>

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
    struct heapComp {
      bool operator() (ListNode* l, ListNode* r) {
        return l->val > r->val;
      }
    };

    ListNode *mergeKLists(vector<ListNode*>& lists) {
      if(lists.size() == 0) return NULL;
      if(lists.size() == 1) return lists[0];
      std::priority_queue<ListNode*, vector<ListNode*>, heapComp> h;
      for (int i = 0; i != lists.size(); i++) {
        if (lists[i] != NULL) h.push(lists[i]);
      }

      ListNode* head = NULL;
      ListNode* cur = NULL;
      while(!h.empty()) {
        ListNode* tmp = h.top();
        if (head == NULL) {
          head = tmp;
          cur = head;
        } else {
          cur->next = tmp;
          cur = cur->next;
        }
        h.pop();
        tmp = tmp->next;
        if(tmp != NULL) h.push(tmp);
      }      
      return head;
    }
};


int main() {
    Solution *s = new Solution();
    ListNode *l1 = new ListNode(5);
    l1 = insert(l1, 2);
    l1 = insert(l1, 1);
    print(l1);
    ListNode *l2 = new ListNode(8);
    l2 = insert(l2, 4);
    l2 = insert(l2, 0);
    print(l2);
    ListNode *l3 = new ListNode(7);
    l3 = insert(l3, 6);
    l3 = insert(l3, 5);
    print(l3);
    
    vector<ListNode*> a;
    a.push_back(l1);
    a.push_back(l2);
    a.push_back(l3);
    ListNode* r = s->mergeKLists(a);
    print(r);
    return 0;
}


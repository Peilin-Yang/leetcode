#include<vector>
#include<iostream>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void print_v(vector<TreeLinkNode*> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i]->val << ",";
  }
  cout << endl;
}

void PrintMedOrder(TreeLinkNode *root) {
    if(root==NULL)  
        return ;  
    PrintMedOrder(root->left); //递归调用，先序遍历左子树  
    cout << root->val << "->"; // visit the data
    PrintMedOrder(root->right); //递归调用，先序遍历右子树
}

class Solution {
public:

    void connect(TreeLinkNode *root) {
        TreeLinkNode *prev = root, *cur = NULL;
        while (prev) {
            cur = prev;
            while (cur) {
                if (cur->left) {
                    if (cur->right) cur->left->next = cur->right;
                    else {
                        while (cur->next) {
                            if (cur->next->left || cur->next->right) {
                                cur->left->next = cur->next->left?cur->next->left:cur->next->right;
                                break;
                            }
                            cur = cur->next;
                        }
                    }
                }
                if (cur->right) {
                    while (cur->next) {
                        if (cur->next->left || cur->next->right) {
                            cur->left->next = cur->next->left?cur->next->left:cur->next->right;
                            break;
                        }
                        cur = cur->next;
                    }
                }
                if (cur) cur = cur->next;
                else break;
            }
            if (prev->left) prev = prev->left;
            else if (prev->right) prev = prev->right;
            else prev = prev->next;
        }
    }
};

int main() {
  Solution s;

  TreeLinkNode *r = new TreeLinkNode(0);
  TreeLinkNode *r1 = new TreeLinkNode(2);
  TreeLinkNode *r2 = new TreeLinkNode(4);
  TreeLinkNode *r3 = new TreeLinkNode(1);
  TreeLinkNode *r4 = new TreeLinkNode(3);
  TreeLinkNode *r5 = new TreeLinkNode(-1);
  TreeLinkNode *r6 = new TreeLinkNode(5);
  TreeLinkNode *r7 = new TreeLinkNode(1);
  TreeLinkNode *r8 = new TreeLinkNode(6);
  TreeLinkNode *r9 = new TreeLinkNode(8);
  r->left = r1;
  r->right = r2;
  r1->left = r3;
  r2->left = r4;
  r2->right = r5;
  r3->left = r6;
  r3->right = r7;
  r4->right = r8;
  r5->right = r9;
  
  PrintMedOrder(r);
  cout << endl;

  s.connect(r);
  return 0;
}

#include<vector>
#include <queue>
#include <stack>
#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_v(vector<TreeNode*> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i]->val << ",";
  }
  cout << endl;
}

void PrintMedOrder(TreeNode *root) {
    if(root==NULL)  
        return ;  
    PrintMedOrder(root->left); //递归调用，先序遍历左子树  
    cout << root->val << "->"; // visit the data
    PrintMedOrder(root->right); //递归调用，先序遍历右子树
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            stack<TreeNode*> tmp;
            bool has_any_children = false;
            for (int i = 0; i < q_size; i++) {
                TreeNode *f = q.front();
                if (f != root) {
                    if (!tmp.empty()) {
                        if (f == NULL) {
                            if (tmp.top()->val == 0) tmp.pop();
                            else tmp.push(new TreeNode(0));
                        } else {
                            if (tmp.top()->val == f->val) tmp.pop();
                            else tmp.push(f);
                        }
                    } else {
                        if (f == NULL) tmp.push(new TreeNode(0));
                        else tmp.push(f);
                    }
                }
                if (f) {
                    q.push(f->left);
                    q.push(f->right);
                    if (f->left || f->right) has_any_children = true;
                }
                q.pop();
            }
            if (!tmp.empty()) return false;
            if (!has_any_children) break;
        }
        return true;
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(1);
  TreeNode *r1 = new TreeNode(2);
  TreeNode *r2 = new TreeNode(2);
  TreeNode *r3 = new TreeNode(3);
  TreeNode *r4 = new TreeNode(3);
  r1->left = r3;
  r2->left = r4;
  r->left = r1;
  r->right = r2;
  
  PrintMedOrder(r);
  cout << endl;

  cout << s.isSymmetric(r) << endl;
  return 0;
}

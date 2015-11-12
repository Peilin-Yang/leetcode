#include<vector>
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
    void helper(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &last) {
        if (root) {
            helper(root->left, prev, first, last);
            if (prev && prev->val >= root->val) {
                if (!first) {
                    first = prev;
                }
                last = root;
            }
            prev = root;
            helper(root->right, prev, first, last);
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev, *first, *last;
        prev = first = last = NULL;
        helper(root, prev, first, last);
        if (first) {
            std::swap(first->val, last->val);
        }
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(3);
  TreeNode *r1 = new TreeNode(2);
  TreeNode *r2 = new TreeNode(1);
  r->left = r1;
  r->right = r2;
  
  PrintMedOrder(r);
  cout << endl;

  s.recoverTree(r);
  
  PrintMedOrder(r);
  cout << endl;
  return 0;
}

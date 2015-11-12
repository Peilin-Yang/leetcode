#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PrintMedOrder(TreeNode *root) {
    if(root==NULL)  
        return ;  
    cout << root->val << "->"; // visit the data
    PrintMedOrder(root->left); //递归调用，先序遍历左子树  
    PrintMedOrder(root->right); //递归调用，先序遍历右子树
}

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* prev = cur->left;
                while (prev->right) prev = prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
            }
            cur = cur->right;
        }
    }
};

int main() {
  Solution s;

  /*
  TreeNode *r = new TreeNode(5);
  TreeNode *r1 = new TreeNode(4);
  TreeNode *r2 = new TreeNode(8);
  TreeNode *r3 = new TreeNode(11);
  TreeNode *r4 = new TreeNode(13);
  TreeNode *r5 = new TreeNode(4);
  TreeNode *r6 = new TreeNode(7);
  TreeNode *r7 = new TreeNode(2);
  TreeNode *r8 = new TreeNode(1);
  r->left = r1;
  r->right = r2;
  r->left->left = r3;
  r->right->left = r4;
  r->right->right = r5;
  r->left->left->left = r6;
  r->left->left->right = r7;
  r->right->right->right = r8;
  */ 
  TreeNode *r = new TreeNode(1);
  TreeNode *r1 = new TreeNode(2);
  r->left = r1;

  PrintMedOrder(r);
  cout << endl;

  s.flatten(r);
  PrintMedOrder(r);
  cout << endl;
  return 0;
}

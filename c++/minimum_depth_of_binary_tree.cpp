#include<iostream>
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
    PrintMedOrder(root->left); //递归调用，先序遍历左子树  
    cout << root->val << "->"; // visit the data
    PrintMedOrder(root->right); //递归调用，先序遍历右子树
}

class Solution {
public:
    int helper(TreeNode* t, int depth) {
        if (!t->left && !t->right) return depth;
        if (t->left && !t->right) return helper(t->left, depth+1);
        if (!t->left && t->right) return helper(t->right, depth+1);
        return min(helper(t->left, depth+1), helper(t->right, depth+1)); 
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return helper(root, 1);    
    }
};

int main() {
  Solution s;

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
  
  PrintMedOrder(r);
  cout << endl;

  cout << s.minDepth(r) << endl;
  return 0;
}

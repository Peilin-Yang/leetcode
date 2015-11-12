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
    bool helper(TreeNode* root, int sum, int cur_total) {
        cur_total+=root->val;
        if (!root->left && !root->right) return sum == cur_total;
        if (root->left && !root->right) return helper(root->left, sum, cur_total);
        if (!root->left && root->right) return helper(root->right, sum, cur_total);
        return helper(root->left, sum, cur_total) || helper(root->right, sum, cur_total);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return helper(root, sum, 0);
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

  cout << s.hasPathSum(r, 22) << endl;
  return 0;
}

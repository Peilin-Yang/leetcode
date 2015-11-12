#include<iostream>
#include<cstdio>
#include<cmath>

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
    bool reach_leaf(TreeNode* root, int h, int cur, int &total) {
        cout << root->val << " " << cur << endl;
        if (cur == h-1) {
            if (!root->right) total--;
            if (!root->left) total--;
            if (root->left || root->right) return true;
            return false;
        }
        if (reach_leaf(root->right, h, cur+1, total)) return true;
        return reach_leaf(root->left, h, cur+1, total);
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = 1;
        TreeNode *cur = root;
        while (cur->left) {
            cur = cur->left;
            h++;
        }
        int total = pow(2, h)-1;
        if (total == 1) return 1;
        reach_leaf(root, h, 1, total);
        return total;
    }
};

int main() {
  Solution s;

  
  TreeNode *r = new TreeNode(1);
  /*
  TreeNode *r1 = new TreeNode(2);
  TreeNode *r2 = new TreeNode(3);
  TreeNode *r3 = new TreeNode(4);
  TreeNode *r4 = new TreeNode(5);
  TreeNode *r5 = new TreeNode(6);
  TreeNode *r6 = new TreeNode(7);
  TreeNode *r7 = new TreeNode(8);
  TreeNode *r8 = new TreeNode(9);
  TreeNode *r9 = new TreeNode(10);
  r->left = r1;
  r->right = r2;
  r->left->left = r3;
  r->left->right = r4;
  r->right->left = r5;
  r->right->right = r6;
  r->left->left->left = r7;
  r->left->left->right = r8;
  r->left->right->left = r9;
  */

  PrintMedOrder(r);
  cout << endl;

  cout << s.countNodes(r) << endl;
  return 0;
}

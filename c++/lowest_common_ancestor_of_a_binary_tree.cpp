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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        return l && r ? root : l ? l : r;
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(-1);
  TreeNode *r1 = new TreeNode(0);
  TreeNode *r2 = new TreeNode(3);
  TreeNode *r3 = new TreeNode(-2);
  TreeNode *r4 = new TreeNode(4);
  TreeNode *r5 = new TreeNode(8);
  r->left = r1;
  r->right = r2;
  r1->left = r3;
  r1->right= r4;
  r3->left = r5;
  
  PrintMedOrder(r);
  cout << endl;

  TreeNode *ret = s.lowestCommonAncestor(r, r, r5);
  cout << ret->val << endl;
  return 0;
}

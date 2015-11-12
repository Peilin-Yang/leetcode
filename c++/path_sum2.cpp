#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

void print_r(vector<vector<int> >& v) {
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << ",";
    }
    cout << endl;
  }
  cout << endl;
}

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
    void helper(TreeNode *root, int sum, vector<int> cur, int cur_sum, vector<vector<int> >& res) {
        if (!root) return;
        cur.push_back(root->val);
        if (!root->left && !root->right && cur_sum+root->val == sum) {
            res.push_back(cur);
        } else {
            if (root->left) helper(root->left, sum, cur, cur_sum+root->val, res);
            if (root->right) helper(root->right, sum, cur, cur_sum+root->val, res);
        }
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> cur;
        helper(root, sum, cur, 0, res);
        return res;
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
  TreeNode *r8 = new TreeNode(5);
  TreeNode *r9 = new TreeNode(1);
  r->left = r1;
  r->right = r2;
  r->left->left = r3;
  r->right->left = r4;
  r->right->right = r5;
  r->left->left->left = r6;
  r->left->left->right = r7;
  r->right->right->left = r8;
  r->right->right->right = r9;
  
  PrintMedOrder(r);
  cout << endl;

  vector<vector<int> > res;
  res = s.pathSum(r, 22);
  print_r(res);

  return 0;
}

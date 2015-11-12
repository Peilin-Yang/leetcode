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
    bool validate(TreeNode* root, TreeNode* &prev) {
        if (!root) { cout << "111" << endl; return true;}
        if (!validate(root->left, prev)) {cout<<"222" << endl; return false;}
        if (prev && prev->val >= root->val) {cout<<"333"<<endl; return false;}
        prev = root;
        return validate(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return validate(root, prev);
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(1);
  TreeNode *r1 = new TreeNode(1);
  r->left = r1;
  
  PrintMedOrder(r);
  cout << endl;

  cout << s.isValidBST(r) << endl;
  return 0;
}

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
    int helper(TreeNode *root, TreeNode* prev, int res) {
        if (!root) return res;
        res = (prev && prev->val+1==root->val)?res+1:1;
        return max(res, max(helper(root->left, root, res), helper(root->right, root, res)));
    }
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        return helper(root, NULL, 1);
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(1);
  TreeNode *r1 = new TreeNode(2);
  TreeNode *r2 = new TreeNode(3);
  TreeNode *r3 = new TreeNode(4);
  TreeNode *r4 = new TreeNode(5);
  r->left = r1;
  r->right = r2;
  r1->left = r3;
  r1->right = r4;
  
  PrintMedOrder(r);
  cout << endl;

  cout << s.longestConsecutive(r) << endl;
  return 0;
}

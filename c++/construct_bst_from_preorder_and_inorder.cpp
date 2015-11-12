#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      return create(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode *create(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end) {
      if(pre_start > pre_end) return NULL;
      int root = preorder[pre_start];
      TreeNode *ret = new TreeNode(root);
      cout << "root:" << root << endl; 
      int idx;
      for (idx = in_start; idx <= in_end; idx++) {
        //cout << "inorder[" << idx << "]:" << inorder[idx] << endl;
        if (inorder[idx] == root) break;
      }
      cout << idx << endl;
      ret->left = create(preorder, pre_start+1, pre_start+(idx-in_start), inorder, in_start, idx-1);
      ret->right = create(preorder, pre_start+idx-in_start+1, pre_end, inorder, idx+1, in_end);
      return ret;
    }
};

void PrintInOrder(TreeNode *root) {
    if(root==NULL)  
        return ;  
    PrintInOrder(root->left); //递归调用，先序遍历左子树  
    cout << root->val << "->"; // visit the data
    PrintInOrder(root->right); //递归调用，先序遍历右子树
}

int main() {
  Solution s;

  int a[] = {5,3,2,1,4,8,7,6,9};
  vector<int> pre(a, a+sizeof(a)/sizeof(int));
  int b[] = {1,2,3,4,5,6,7,8,9};
  vector<int> in(b, b+sizeof(b)/sizeof(int));

  TreeNode *ret = s.buildTree(pre, in);
  PrintInOrder(ret);
  cout << endl;
  return 0;
}

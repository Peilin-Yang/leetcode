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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      return create(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode *create(vector<int> &postorder, int post_start, int post_end, vector<int> &inorder, int in_start, int in_end) {
      if(post_start > post_end) return NULL;
      int root = postorder[post_end];
      TreeNode *ret = new TreeNode(root);
      cout << "root:" << root << endl; 
      int idx;
      for (idx = in_start; idx <= in_end; idx++) {
        //cout << "inorder[" << idx << "]:" << inorder[idx] << endl;
        if (inorder[idx] == root) break;
      }
      cout << idx << endl;
      ret->left = create(postorder, post_start, post_start+(idx-in_start-1), inorder, in_start, idx-1);
      ret->right = create(postorder, post_start+idx-in_start, post_end-1, inorder, idx+1, in_end);
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

  int a[] = {1,4,3,2,6,9,8,7,5};
  vector<int> post(a, a+sizeof(a)/sizeof(int));
  int b[] = {1,2,3,4,5,6,7,8,9};
  vector<int> in(b, b+sizeof(b)/sizeof(int));

  TreeNode *ret = s.buildTree(in, post);
  PrintInOrder(ret);
  cout << endl;
  return 0;
}

#include<climits>
#include<iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int h(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = max(0, h(root->left, res));
        int r = max(0, h(root->right, res));
        res = max(res, l+r+root->val);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        h(root, res);
        return res;
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(1);
  TreeNode *r1 = new TreeNode(2);
  TreeNode *r2 = new TreeNode(3);
  r->left = r1;
  r->right = r2;
  
  cout << s.maxPathSum(r) << endl;
  return 0;
}

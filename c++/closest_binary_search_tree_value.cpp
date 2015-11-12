#include<climits>
#include<cmath>
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
    void h(TreeNode* root, double target, double& min_diff, int& res) {
        if (!root) return;
        if (fabs(target-root->val) < min_diff) {
            res = root->val;
            min_diff = fabs(target-root->val);
        }
        if (root->val > target) h(root->left, target, min_diff, res);
        else h(root->right, target, min_diff, res);
    }
    int closestValue(TreeNode* root, double target) {
        int res;
        double min_diff = INT_MAX+1;
        h(root, target, min_diff, res);
        return res;
    }
};

int main() {
  Solution s;

  TreeNode *r = new TreeNode(1);
  //TreeNode *r1 = new TreeNode(2);
  //TreeNode *r2 = new TreeNode(3);
  //r->left = r1;
  //r->right = r2;
  
  cout << s.closestValue(r, 4.428571) << endl;
  return 0;
}

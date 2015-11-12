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

class BSTIterator {
private:
    TreeNode *_root;
    TreeNode *_cur;
    TreeNode *_n;
public:
    BSTIterator(TreeNode *root) {
        _root = root;
        _cur = root;
        while (_cur && _cur->left) _cur = _cur->left;
        _n = _cur;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (_cur && _cur == _n) {
            TreeNode *tmp;
            if (_cur->right) {
                tmp = _cur->right;
                while(tmp->left) tmp = tmp->left;
                _n = tmp;
            } else {
                tmp = _root;
                TreeNode *n = NULL;
                while (tmp) {
                    if (tmp->val > _cur->val) {
                        n = tmp;
                        tmp = tmp->left;
                    } else if (tmp->val < _cur->val) {
                        tmp = tmp->right;
                    } else break;
                }
                _n = n;
            }
            return true;
        }
        return false;
    }

    /** @return the next smallest number */
    int next() {
        int r = _cur->val;
        _cur = _n;
        return r;
    }
};


int main() {
  TreeNode *r = NULL;
  //TreeNode *r = new TreeNode(2);
  //TreeNode *r1 = new TreeNode(1);
  //r->left = r1;
  
  //PrintMedOrder(r);
  //cout << endl;

  BSTIterator i = BSTIterator(r);
  while (i.hasNext()) {
    cout << i.next() << "->";
  }
  cout << endl;


  return 0;
}

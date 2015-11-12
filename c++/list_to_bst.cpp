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

class Solution {
public:
    vector<int> list_to_array(ListNode *head) {
      vector<int> ret;
      while(head != NULL) {
        ret.push_back(head->val);
        head = head->next;
      }
      return ret;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
      int len = num.size();
      if (len == 0) return NULL;
      if (len == 1) return new TreeNode(num[0]);
      int median = (len%2==0) ? (len/2-1) : (len/2);
      TreeNode *ret = new TreeNode(num[median]);
      vector<int> first(num.begin(), num.begin()+median);
      vector<int> second(num.begin()+median+1, num.end());
      TreeNode *l = sortedArrayToBST(first);
      TreeNode *r = sortedArrayToBST(second);
      ret->left = l;
      ret->right = r;
      return ret;
    }

    TreeNode *sortedListToBST(ListNode *head) {
      vector<int> a = list_to_array(head);
      return sortedArrayToBST(a);
    }
};

void PrintMedOrder(TreeNode *root) {
    if(root==NULL)  
        return ;  
    PrintMedOrder(root->left); //递归调用，先序遍历左子树  
    cout << root->val << "->"; // visit the data
    PrintMedOrder(root->right); //递归调用，先序遍历右子树
}

int main() {
  Solution s;

  int a[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  TreeNode *ret = s.sortedArrayToBST(n);
  PrintMedOrder(ret);
  cout << endl;
  return 0;
}

#include<queue>
#include<vector>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            int s = q.size();
            string empty;
            for (int i = 0; i < s; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    res+=std::to_string(cur->val)+",";
                    q.push(cur->left);
                    q.push(cur->right);
                } else res+="#,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string tmp;
        vector<string> t;
        while(getline(s,tmp,',')) {
           if (tmp.empty()) continue;
           t.push_back(tmp); 
        }
        TreeNode* root = t.empty()?NULL:new TreeNode(stoi(t[0]));
        TreeNode* cur = root;
        queue<TreeNode*> q;
        if (cur) q.push(cur);
        int idx = 1;
        while(!q.empty()) {
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
            TreeNode* tree = q.front();
            q.pop();
            if (idx < t.size()) {
                if (t[idx] == "#") tree->left = NULL;
                else {
                    TreeNode* l = new TreeNode(stoi(t[idx]));
                    tree->left = l;
                    q.push(l);
                }
            }
            idx++; 
            if (idx < t.size()) {
                if (t[idx] == "#") tree->right = NULL;
                else {
                    TreeNode* r = new TreeNode(stoi(t[idx]));
                    tree->right = r;
                    q.push(r);
                }
            }
            idx++; 
            }
        }
        return root;
    }
};

int main() {
  Codec s;

  TreeNode *r = new TreeNode(1);
  TreeNode *r1 = new TreeNode(2);
  TreeNode *r2 = new TreeNode(3);
  TreeNode *r3 = new TreeNode(4);
  TreeNode *r4 = new TreeNode(5);
  r->left = r1;
  r->right = r2;
  r2->left = r3;
  r2->right = r4;
  
  PrintMedOrder(r);
  cout << endl;

  string t;
  t = s.serialize(r);
  cout << t << endl;
  TreeNode *res = s.deserialize(t);
  PrintMedOrder(res);
  cout << endl;

  return 0;
}

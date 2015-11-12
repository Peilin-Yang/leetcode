#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /*
        If number of ( is less than n, you can add (;
        If number of ) is less than number of (, you can add ).
        */
        vector<string> r;
        g(r, "", n, n);
        return r;
    }
    void g(vector<string>& r, string cur_r, int n1, int n2) {
        if (n1 == 0 && n2 == 0) r.push_back(cur_r);
        else {
            if (n1 > 0) g(r, cur_r+"(", n1-1, n2);
            if (n2 > n1) g(r, cur_r+")", n1, n2-1);
        }
    }
};

int main() {
  Solution s;

  vector<string> r = s.generateParenthesis(3);

  for (int i = 0; i != r.size(); i++) {
    cout << r[i] << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void p(vector<vector<string> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        //cout << start << "," << end << endl;
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
    void helper(string s, int start, vector<string> cur, vector<vector<string> >& res) {
        int n = s.size();
        if (start == n) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < n; i++) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i-start+1));
                helper(s, i+1, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        vector<string> cur;
        vector<vector<string> > res;
        helper(s, 0, cur, res);
        return res;
    }
};

int main() {
  Solution s;

  string t;
  vector<vector<string> > r;

  t = "aba"; 
  r = s.partition(t);
  p(r);

  return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print_v(vector<int>& r) {
  for (int i = 0; i != r.size(); i++) {
      cout << r[i] << ",";
  }
  cout << endl;
}

class Solution {
public:
    void helper(vector<int> s, int k, vector<vector<int> >& r, vector<int>& rr, int start) {
        if (rr.size() == k) {
            r.push_back(rr);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            rr.push_back(s[i]);
            //swap(s[i], s[start]);
            helper(s, k, r, rr, start+1);
            rr.pop_back();
            start++;
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> s;
        for (int i = 0; i < n; i++) s.push_back(i+1);
        vector<vector<int> > r;
        vector<int> rr;
        helper(s,k,r,rr,0);
        return r;
    }
};

void print_solution(vector<vector<int> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution s;

  vector<vector<int> > r = s.combine(4, 2);
  print_solution(r);

  return 0;
}

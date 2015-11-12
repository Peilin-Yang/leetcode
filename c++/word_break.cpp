#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

void print_solution(vector<vector<bool> >& flags) {
  //cout << "i:" << flags.size() << endl;
  for(int i = 0; i != flags.size(); i++) {
    //cout << "j:" << flags[i].size() << endl;
    for(int j = 0; j != flags[i].size(); j++) {
      cout << flags[i][j] << ",";
    }
    cout << endl;
  }
}

void print_b(vector<vector<bool> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}

void print_r(vector<string>& r) {
  for (int i = 0; i != r.size(); i++) {
      cout << r[i] << ",";
  }
  cout << endl;
}

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int l = s.size();
        vector<bool> dp(l+1, false);
        
    }
};

int main() {
  Solution s;

  unordered_set<string> t;
  //t.insert("leet");
  //t.insert("code");
  t.insert("a");
  cout << boolalpha << s.wordBreak("a", t) << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty() || wordDict.empty()) return res;
        int n = s.size();
        vector<bool> dp(n+1, false);
        vector<vector<string> > m(n+1, vector<string>());
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string cur = s.substr(j, i-j);
                if (dp[j] && wordDict.find(cur) != wordDict.end()) {
                    dp[i] = true;
                    if (m[j].empty()) m[i].push_back(cur);
                    else {
                        vector<string> tmp = m[j];
                        for (int k = 0; k < tmp.size(); k++) {
                            string s_tmp = tmp[k]+" "+cur;
                            m[i].push_back(s_tmp);
                        }
                    }
                }
            }
        }
        return m[n];
    }
};

int main() {
  Solution s;

  unordered_set<string> t;
  t.insert("cat");
  t.insert("cats");
  t.insert("and");
  t.insert("sand");
  t.insert("dog");
  vector<string> r = s.wordBreak("catsanddog", t);
  print_r(r);

  return 0;
}

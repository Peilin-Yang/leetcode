#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
      vector<string> ret;
      int l = strs.size();
      unordered_map<string, vector<string> > m;
      for(int i = 0; i != l; i++) {
        string tmp(strs[i]);
        std::sort(strs[i].begin(), strs[i].end());
        if (m.find(strs[i]) == m.end()) {
          m[strs[i]] = vector<string>();
        } else {
          if (m[strs[i]].size() == 1) {
            ret.push_back(m[strs[i]][0]);
          }
          ret.push_back(tmp);
        }
        m[strs[i]].push_back(tmp);
      }
      return ret;
    }
};

int main() {
  Solution s;

  string a[] = {"tea","and","ate","eat","dan"};
  vector<string> n(a, a+sizeof(a)/sizeof(string));
  vector<string> r = s.anagrams(n);
  for (int i = 0; i != r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}

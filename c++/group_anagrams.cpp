#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        vector<std::unordered_map<char, int> > m;
        int i = 0, j = 0, k = 0;
        for (i = 0; i != strs.size(); i++) {
            std::unordered_map<char, int> this_m;
            for (j = 0; j != strs[i].size(); j++) {
                this_m[strs[i][j]]++;
            }
            for (k = 0; k != m.size(); k++) {
                bool found = true;
                for (auto c:this_m) {
                    if (m[k].find(c) == std::unordered_map::npos || m[k][c] != this_m[c]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    res[k].push_back(strs[i]);
                    break;
                }
            }
            if (k == m.size()) {
                m.push_back(this_m);
                res.push_back(vector<string> (1, strs[i]));
            }
        }
        return res;
    }
};

int main() {
  Solution s;

  string a[] = {"tea","and","ate","eat","dan"};
  vector<string> n(a, a+sizeof(a)/sizeof(string));
  vector<vector<string> > r = s.anagrams(n);
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}

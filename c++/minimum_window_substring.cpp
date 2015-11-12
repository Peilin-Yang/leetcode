#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;

void print_v(vector<string> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}


void print_r(vector<vector<int> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}


class Solution {
public:
    string minWindow(string s, string t) {
        int l = s.size();
        string r;
        unordered_map<char, int> m;
        unordered_map<char, int> required;
        bool all_exist = false;
        int start = 0, min_len = INT_MAX;
        for (int i = 0; i != t.size(); i++) {
            required[t[i]]++;
            m[t[i]] = 0;
        }
        for (int i = 0; i != l; i++) {
            if (m.find(s[i]) != m.end()) {
                m[s[i]]++;
                if (!all_exist) {
                    all_exist = true;
                    unordered_map<char, int>::iterator it;
                    for (it = m.begin(); it != m.end(); it++) {
                        if (it->second < required[it->first]) {
                            all_exist = false;
                            break;
                        }
                    }
                }
                if (all_exist) {
                    while (start <= i) {
                        if (m.find(s[start]) != m.end()) {
                            if (m[s[start]] > required[s[start]]) m[s[start]]--;
                            else break;
                        }
                        start++;
                    }
                    int range = i-start+1;
                    if (range < min_len) {
                        min_len = range;
                        r = s.substr(start, range);
                    }
                }
            }
        }
        return r;
    }
};


int main() {
  Solution s;

  string ss("ADOBECODEBANC");
  string t("ABC");
  string r;
  //r = s.minWindow(ss, t);
  //r = s.minWindow("abac", "aa");
  //r = s.minWindow("ab", "b");
  r = s.minWindow("aab", "aab");
  cout << r << endl;
  return 0;
}

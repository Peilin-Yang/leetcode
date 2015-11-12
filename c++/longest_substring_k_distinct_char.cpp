#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void print_v(vector<string> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}

void print_m(unordered_map<char, int> & m) {
  for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << "->" << it->second << ",";
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
    string maxSubStringKUniqueChars(string s, int k) {
        unordered_map<char, int> m;
        int l = s.size();
        int start = 0, max_len = 0;
        string r;
        for (int i = 0; i != l; i++) {
            m[s[i]]++;
            while (m.size() > k) {
                int c = s[start];
                int n = m[s[start]];
                if (n > 1) m[s[start]]--;
                else m.erase(s[start]);
                start++;
            }
            if (m.size() == k) {
                int range = i-start+1;
                if (range > max_len) {
                    max_len = range;
                    r = s.substr(start, range);
                }
            }
        }
        print_m(m);
        return max_len == 0?s:r;
    }
};


int main() {
  Solution s;

  string r("abcbefffeegdabbeffgbbacdddccaaa");
  //string r("abbaaba");
  cout << s.maxSubStringKUniqueChars(r, 3) << endl;
  return 0;
}
